#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int m=0, num =0,j=0;

struct pnum
{
  int n;
  int result;
};

void *quaseprimo_maluco(void *s){
    struct pnum *c = (struct pnum *) s;
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

}

int main(void){

    scanf("%d",&m);
    while(1)
    {   
        int aux =0;
        pthread_t t1,t2;
        struct pnum a,b;
        if(scanf("%d", &num)== EOF){
            break;
        }
        a.n = num;
        a.result =0;
        aux =1;
        j++;
        pthread_create(&t1,NULL, &quaseprimo_maluco,&a);

        if(m % 2 != 0 && j == m){
            pthread_join(t1,NULL);
            printf("%d\n",a.result);
            exit(0);
        }else{
            if(scanf("%d", &num)== EOF){
                break;
            }
            b.n = num;
            b.result =0;
            j++;
            pthread_create(&t2,NULL, &quaseprimo_maluco,&b);
        }
        

        pthread_join(t1,NULL);
        printf("%d\n",a.result);
        pthread_join(t2,NULL);
        printf("%d\n",b.result);
    }
    
    return 0;
}