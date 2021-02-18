#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int m1[2000][2000],m2[2000][2000];
int m3[2000][2000];

struct multmatriz
{
  int inicio;
  int fim;
  int size;
};

void *multiplica(void *s)
{
    struct multmatriz *b = (struct multmatriz *) s;
    //printf("inicio: %d\n", b->inicio);
    // printf("fim: %d\n", b->fim);
    // printf("size: %d\n", b->size);
    for(int i=b->inicio;i<b->fim;i++)
        for(int j=0;j<b->size;j++)
        {
        for(int k=0;k<b->size;k++)
            m3[i][j]+=m1[i][k]*m2[k][j];
        }
    int r=0;
    pthread_exit((void *)&r);
}

int main(void){
    int m;
    scanf("%d",&m);
    
    for (int i=0; i<m; i++ ){
        for (int j=0; j<m; j++ ){
            scanf("%d", &m1[i][j]);
            m3[i][j]=0;
        }
    }

    for (int i=0; i<m; i++ ){
        for (int j=0; j<m; j++ ){
            scanf("%d", &m2[i][j]);
        }
    }

    struct multmatriz a,b;
    a.size = m;
    b.size = m;
    int threads=2;
    int divisao=m/threads;
    int resto=m%threads;
    pthread_t t1,t2;
    b.inicio = divisao;
    b.fim=resto+divisao*2;      
    a.inicio = 0;
    a.fim=divisao;
    pthread_create(&t1,NULL, multiplica,&a);
    pthread_create(&t2,NULL, multiplica,&b);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    for(int i=0;i<m;i++)
    {
        printf("%d ",m3[i][0]);
        for(int j=1;j<m;j++){
            if (j == m - 1) {
                    printf("%d",m3[i][j]);   
                }else{
                    printf("%d ",m3[i][j]);
                }      
        }
        printf("\n");
    }
    return 0;
}