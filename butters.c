#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

int aleatorios[50000],tamanho=0, result =0;
sem_t sem1;
struct params{
    int i;
    pthread_t tid;
};

void * procura(void *s){
    sem_wait(&sem1);
    struct params * st = (struct params *) s;
    int tem =0, aux1 = st->i;
    
    //printf(" teste %d\n",aux1);
        for(int j=0; j<tamanho; j++){
            
            for(int k=1;k<10000;k++){
                rand_r(&aux1);
            }
            int b=0;
            b = (rand_r(&aux1)%256);
            
            //printf("teste %d\n",b);
            if(b != aleatorios[j]){
                tem=-1;
                sem_post(&sem1);
                pthread_exit(0);               
                // break;
            }
            
        }
        
        if(tem == 0){
            //result = st->i;
            printf("%d\n",st->i);
            sem_post(&sem1);
            pthread_exit(0);
        }
        sem_post(&sem1);
}

int main() {
    int mi,mf,a;
    scanf("%d",&mi);
    scanf("%d",&mf);
    
    while(1){
        if(scanf(" %d", &a)== EOF){
            break;
        }
        aleatorios[tamanho] = a;
        tamanho++;
    }

    if(mi-mf == 0){
        printf("%d\n",mi);
        return 0;
    }
    struct params casos[50000];
    int t =0;
    sem_init(& sem1, 0, 2);
    for(int i=mi; i<=mf; i++){
        casos[t].i =i;
        pthread_create(&casos[t].tid,NULL, &procura,&casos[t]);
        t++;
    }
    t=0;
    for(int i=mi; i<=mf; i++){
       pthread_join(casos[t].tid,NULL);
       t++;
    }
    
    return 0;
}
