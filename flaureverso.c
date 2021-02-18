#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void igor3k(int s){
    char nome[10];
    if(scanf(" %s", nome)== -1){
        exit(0);
    }
    if(strcmp(nome,"Igor3k") == 0){
        printf("Certo\n");
    }else{
        printf("Erro\n");
        kill(getppid(),SIGALRM);
        
    }
}

void monark(int s){
    char nome[10];
    if(scanf(" %s", nome)== -1){
        exit(0);
    }
    if(strcmp(nome,"Monark") == 0){
        printf("Certo\n");
    }else{
        printf("Erro\n");
        kill(getppid(),SIGALRM);
    }
}

void convidado1(int s){
    char nome[10];
    if(scanf(" %s", nome)== -1){
        exit(0);
    }
    if(strcmp(nome,"Con1") == 0){
        printf("Certo\n");
    }else{
        printf("Erro\n");
        kill(getppid(),SIGALRM);
    }
}

void convidado2(int s){
    char nome[10];
    if(scanf(" %s", nome)== -1){
        exit(0);
    }
    if(strcmp(nome,"Con2") == 0){
        printf("Certo\n");
    }else{
        printf("Erro\n");
        kill(getppid(),SIGALRM);
    }
}

void geral(int s){
    char nome[10];
    if(scanf(" %s", nome)== -1){
        exit(0);
    }
    if(strcmp(nome,"Silencio") == 0){
        printf("Certo\n");
    }else{
        printf("Erro\n");
        kill(getppid(),SIGALRM);
    }
}

int main() {
    signal(SIGUSR1,igor3k);
    signal(SIGUSR2,monark);
    signal(SIGINT,convidado1);
    signal(SIGTERM,convidado2);
    signal(SIGALRM,geral);

    while (1)
    {
        pause(); 
    }
    return 0;
}
