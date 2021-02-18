#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <semaphore.h>

int m=0, num =0,j=0, n=0;
sem_t sem1, sem2;

struct pnum
{
  int n;
  int result;
  pthread_t tid;
};

void *quaseprimo_maluco(void *s){
    sem_wait(&sem1);
    struct pnum *c = (struct pnum *) s;
    if( c->n < 508079){
        c->result = 508079;
        sem_post(&sem1);
        pthread_exit(0);
    }
    
    int div = c->n + 1;
    while(1){   
        if(div==1|| div%2==0){     
            div++;
        }

        int count=0;
        for(int i=3,f=floor(sqrt(div));i<f;i+=2){
            if(div%i==0 && i<11){
                break;
            }
            else if(div%i==0 && i>10){
                 count++;
            }
        }
        if(count>10){
            c->result = div;
            break;
        } 
        div++;
    }
    sem_post(&sem1);
}

int main(void){

    scanf("%d",&m);

    struct pnum PARAMETRO[m];
    sem_init(& sem1, 0, 2);
    sem_init(& sem2, 0, 10);
    for(int i=0; i<m; i++)
    {
        sem_wait(&sem2);
        scanf("%d",&n);

        PARAMETRO[i].n= n;
        
        pthread_create(&PARAMETRO[i].tid,NULL, &quaseprimo_maluco,&PARAMETRO[i]);
        sem_post(&sem2);
    }

    for(int i=0; i<m; i++)
    {
         pthread_join(PARAMETRO[i].tid,NULL);
        
    }
    
    for(int i=0; i<m; i++)
    {
        printf("%d\n",PARAMETRO[i].result);
        
    }
    
    return 0;
}