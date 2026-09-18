#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    pid_t pid=fork();
    
    if(pid<0){
        return 1;
    }
    else if(pid==0){
        execl("/bin/ls","ls",NULL);
        perror("Failed");
        return 1;

    }
    
    waitpid(pid,NULL,0);
    pid=fork();
    if(pid<0)return 1;
        else if(pid==0){
        printf("\n");
        
        execl("/bin/date","ls",NULL);
        perror("Failed2");
        return 1;
    }
        
    waitpid(pid,NULL,0);
    printf("Parent process done:\n");

    
    return 0;
}

