#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int page[50000], anomalia=0;

struct queue{
  int inicio, fim, ultimofault, ultimopage;
};

int main() {
    int m=0;

    scanf("%d",&m);
    
    int list[m];

    for (int i=0; i<m; i++ ){
            scanf("%d", &list[i]);
    }
    struct queue fila;
    fila.ultimofault=0;
    fila.ultimopage=0;
    while(1){
        int a, fault=0;
        
        if(scanf(" %d", &a)== EOF){
            break;
        }
        fila.inicio = 0;
        fila.fim = a - 1;
        for (int j=fila.inicio; j<fila.fim+1; j++ ){
            page[j] = -1;
        }

        for (int i=0; i<m; i++ ){
            int tem=0;
            for (int j=fila.inicio; j<fila.fim+1; j++ ){

                if(page[j] == list[i]){
                    tem = 1;
                    break;
                }
                
            }

            if(tem == 0){

                fault++;
                page[fila.fim + 1] = list[i];
                fila.fim++;
                fila.inicio++;
            }
        }
        printf("%d %d\n",a, fault);
        if(fila.ultimopage == 0){
            //printf("entrou 1\n");
            fila.ultimopage= a;
            fila.ultimofault = fault;
            anomalia ++;
        }
        if(a < fila.ultimopage){
            //printf("entrou 2\n");

            //printf("ult %d\n", fila.ultimofault);
            if(fila.ultimofault > fault){
                //printf("entrou 3\n");
                anomalia ++;
            }
            fila.ultimopage= a;
            fila.ultimofault = fault;
        }else if( a > fila.ultimopage){
            //printf("entrou 4\n");
            if(fila.ultimofault < fault){
                //printf("entrou 5\n");
                anomalia ++;
            }
        }

        // if(fault > fila.ultimofault){
        //     //printf("entrou\n");
        //     fila.ultimofault = fault;
        //     anomalia ++;
        // }
        
    }
    //printf("ult %d\n", fila.ultimopage);
    //printf("ult %d\n", fila.ultimofault);
    if(anomalia > 1){
        printf("Belady detectado\n");
    }else{
        printf("Sem anomalia\n"); 
    }

    return 0;
}
