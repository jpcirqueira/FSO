#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

int m=0,results[50000],tam=0;
sem_t sem1;
struct params{
    int i;
    pthread_t tid;
};

int ordena(const void *e1, const void *e2) {

   if ( *(int *)e1 > * (int *)e2) {
      return 1;

   } else if ( *( int * )e1 < *(int *)e2) {
      return -1;
   } else {
      return 0;

   }
}

void * procura(void *s){
    sem_wait(&sem1);
    struct params * st = (struct params *) s;
    int tem =0, aux1 = st->i;
          
    for(int k=1;k<100000;k++){
        rand_r(&aux1);
    }
    int b=0;
    b = (rand_r(&aux1)%8);
    if(m == b){
        //printf("teste\n");
        results[tam] = st->i;
        tam++;
        // printf("%d\n",st->i);
    }       
    sem_post(&sem1);
}

int main() {
    int mi,mf,a;
    scanf("%d",&mi);
    scanf("%d",&mf);
    scanf("%d",&m);
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
    qsort(results, tam, sizeof(int), ordena);
    
    for(int k =0; k <tam; k++){
        printf("%d\n",results[k]);
    }
    return 0;
}
