#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int senha=0, msg_secreta=0;

void sinal_sigterm(int sinal) {
     printf("Recebi %d\n", sinal);

    if(senha == 2)
    {
        //msg_secreta = 1;
        printf("Senha acionada\n");
        senha =3;
    }else{
      senha = 0;
      //msg_secreta = 0;
    }
}


void sinal_usr2(int sinal){
  printf("Recebi %d\n", sinal);
     if(senha == 1){ 
         senha = 2;
         //msg_secreta = 0;
    }else{
      senha = 0;
      //msg_secreta = 0;
    }

}

void sinal_sigint(int sinal){
    printf("Recebi %d\n", sinal);
    senha = 1;
    //msg_secreta = 0;
}

void sinal_usr1(int sinal){
  printf("Recebi %d\n", sinal);
  if( senha == 3){
      printf("Tchau\n");
      exit(0);
  }else{

    senha = 0;
  }
    
}


int main() {
    
    signal(SIGTERM, sinal_sigterm);
    signal(SIGUSR2, sinal_usr2);
    signal(SIGINT, sinal_sigint);

    signal(SIGUSR1, sinal_usr1);
    

    while (1)
    {
        pause(); 
    }

return 0;
}
