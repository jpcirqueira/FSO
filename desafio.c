#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

enviasigntfilhos(int a){
// kill(a,SIGINT);
//     kill(b,SIGINT);
    printf("recebi o sinal %d do paizao\n", a);
    
    // printf("sou o filho 1");
    // printf("%d\n",a);
    // printf("sou o filho 2");
    // printf("%d\n",b);
    //printf("%d",c)
}
void faz100(){
    sleep(1);
    printf("%d: sou paizão to enviando sigint para o %d\n",getpid(),getpid()+1);
    kill(getpid()+1,SIGINT);
    
}

void faz101(){
    int pai = getpid();
    printf("%d sou pai\n",pai);
    pid_t a = fork();
    
    if(a==0){
        printf("%d sou filho1\n",getpid());
        // faz102(pai);
        return 0;
    }

    pid_t b = fork();

    if(b==0){
        printf("%d sou filho2\n",getpid());
        // faz103(pai);
        return 0;
    }
    
        printf("entrei aqui\n");
        sleep(5);
        while(1){
            signal(SIGINT, enviasigntfilhos);
        }
            
}

// void faz102(int s){
//     kill(s,SIGTERM);
//    //kill();
// }


// void faz103(int s){
//     sleep(4);
//     kill(s,SIGTERM);
//     //kill();
// }

int main(void){
    printf("%d sou paizão\n",getpid());
    pid_t a = fork();
    //printf("%d: esse é o pid de a\n",a);
    //printf("%d: esse é o pid do pai\n",getpid());
    // printf("%d: esse é o pid de a",%a)
    
    if(a>0){
        faz100();
    }else if(a==0){
        faz101();
    }else{
        printf("deu errado\n");
    }    
}