#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int m1[50000];
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int maior = 0;
struct v
{
  int inicio;
  int fim;
};

void *compara(void *l){
    
    struct v *b =(struct v*) l;

    //printf("inicio: %d \n", b->inicio);
    for(int i=b->inicio; i<b->fim; i++){
        
        if(m1[i] > maior){
            pthread_mutex_lock(&m);
            maior = m1[i];
            pthread_mutex_unlock(&m);
        }
    }
    
    pthread_exit((void *)&maior);
}


int main(void){
    srand(time(NULL));
    for(int i=0; i<50000; i++){
        m1[i] = rand() %50000;
        //printf("%d ", m1[i]);
    }
    
    //int threads=4;
    //pthread_t ids[threads];
    pthread_t t1,t2,t3,t4;
    struct v a,b,c,d;
    a.inicio=0;  
    a.fim= 50000/4;
    b.inicio=50000/4;  
    b.fim= 50000/3;
    c.inicio=50000/3;  
    c.fim= 50000/2;
    d.inicio=50000/2;  
    d.fim= 50000;
    pthread_create(&t1,NULL, compara,&a);
    pthread_create(&t2,NULL, compara,&b);
    pthread_create(&t3,NULL, compara,&c);
    pthread_create(&t4,NULL, compara,&d);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    printf("maior: %d \n", maior);
    //for(int j=0; j<3; j++){
    //     struct v *t;
    //     t=malloc(sizeof(struct v));
    //     if(j==1){
    //         t->inicio= 5000/4;  
    //         t->fim= 5000/3;
    //     }

    //     else if(j ==2){
    //         t->inicio= 5000/3;  
    //         t->fim= 5000/2;
    //     }
            
    //     else if(j == 3){
    //         t->inicio= 5000/2;  
    //         t->fim= 5000;            
    //     }

    //     else{
    //         t->inicio=0;  
    //         t->fim= 5000/4;              
    //     }
    //     // fprintf(stderr,"--> %d %d\n",t->inicio,t->fim);
    //     pthread_create(&ids[j],NULL, compara,(void*)t);
    // }

    // for(int i=0;i<threads;i++){
    //         pthread_join(ids[i],NULL);
    // }
    
    return 0;
}