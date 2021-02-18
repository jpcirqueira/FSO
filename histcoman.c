#include <stdio.h>

int main(){
    int m,e, maiornum=0,tam;

    while(1){
        scanf( "%i", &m );
        int comand[m];
        if(m == 0){
            break;
        }
        for(int i=0; i<m; i++){
            scanf( "%i", &e );
            comand[i] =  e;
            if(e > maiornum){
                maiornum = e;
            }
        }

        tam = m + maiornum;
        int hist[tam],aux = maiornum;
        for(int j = 0; j < maiornum; j++){
            hist[j] = aux;
            aux--;
        }
        int tamanhoatual = maiornum -1, soma=0;
        for(int i = 0; i<m;i++){
            int aux1=1;
            for(int j=tamanhoatual;j>=0;j--){
                if(comand[i] == hist[j]){
                    soma += aux1;
                    tamanhoatual++;
                    hist[tamanhoatual] = comand[i];
                    break;
                }
                aux1++;
            }
            
        }
        printf("%d\n", soma);
    }
    return 0;
}