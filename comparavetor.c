#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int m1[2000],m2[2000];
int aux = 0, diferente = 0;
int m= 0;

struct compmatriz
{
  int inicio;
  int fim;
};

void *ordena(void *s){  
    int *matriz = (int *)s;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if (matriz[i] < matriz[j]){
                aux = matriz[i];
                matriz[i] = matriz[j];
                matriz[j] = aux;
            }
        }
    }
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
    pthread_create(&t1,NULL, ordena,&m1);
    pthread_create(&t2,NULL, ordena,&m2);
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
        printf("Não são iguais\n");
    }else{
        printf("São iguais\n");
    }
    return 0;
}