#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int aleatorios[50000];

int main() {
    int mi,mf,a,aux=0;
    scanf("%d",&mi);
    scanf("%d",&mf);
    
    while(1){
        if(scanf(" %d", &a)== EOF){
            break;
        }
        aleatorios[aux] = a;
        aux++;
    }

    if(mi-mf == 0){
        printf("%d\n",mi);
        exit(0);
    }

    // for(int j=0; j<aux; j++){
    //     printf("teste %d\n", aleatorios[j]);
    // }

    for(int i=mi; i<=mf; i++){
        //printf("%d\n",i);
        int tem =0,aux1=i;
        for(int j=0; j<aux; j++){
            for(int k=1;k<10000;k++){
                rand_r(&aux1);
            }
            int b=0;
            b = (rand_r(&aux1)%256);
            if(b != aleatorios[j]){
                //printf("teste\n");
                //printf("%d\n",i);
                tem=-1;
                break;
            }
            
        }
        if(tem == 0){
            printf("%d\n",i);
            exit(0);
        }
    }
   
    return 0;
}
