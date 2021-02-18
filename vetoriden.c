#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int m1[10000000],m2[10000000];
int diferente = 0, m= 0;

struct compmatriz
{
  int inicio;
  int fim;
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

void *ordenacao(void *s){  
    int *vetor = (int *)s;
    qsort(vetor, m, sizeof(int), ordena);
    int r =0;
    pthread_exit((void *)&r);
}

void *compara(void *s){
    struct compmatriz *b = (struct compmatriz *) s;
    for (int i = b->inicio; i < b->fim; i++){
        if(m1[i] != m2[i]){
            diferente = 1;
        }
    }
    int r =0;
    pthread_exit((void *)&r);
}

int main(void){
    scanf("%d",&m);
    
    for (int i=0; i<m; i++ ){
            scanf("%d", &m1[i]);
            
    }

    for (int i=0; i<m; i++ ){
            scanf("%d", &m2[i]);
    }
    pthread_t t1,t2;
    //qsort(m1, m, sizeof(int), ordena);
    //qsort(m2, m, sizeof(int), ordena);
    pthread_create(&t1,NULL, ordenacao,&m1);
    pthread_create(&t2,NULL, ordenacao,&m2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    struct compmatriz a,b;
    a.inicio = 0;
    a.fim = m/2;
    b.inicio = m/2;
    b.fim = m;
    pthread_create(&t1,NULL, compara,&a);
    pthread_create(&t2,NULL, compara,&b);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    if(diferente == 1){
        printf("Diferentes\n");
    }else{
        printf("Mesmos elementos\n");
    }
    return 0;
}