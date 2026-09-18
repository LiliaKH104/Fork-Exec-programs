#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
int main(){

	pid_t pid;
	printf("initial PID:%jd\n", (intmax_t)getpid());
	pid= fork();
	if(pid<0){
		printf("Fork is not working");
		return 1;
	}
	else if(pid==0){
		printf("\n");

		printf("Child PID: %jd\n", (intmax_t)getpid());
		printf("Parent PID:%jd\n",(intmax_t)getppid());
		printf("\n");
		
		pid=fork();
		if(pid<0){
			printf("Second Fork is not working");
			return 1;
		}
		else if (pid==0){
			printf("Grandson PID:%jd\n",(intmax_t)getpid());
			printf("Child PID:%jd\n",(intmax_t)getppid());
		}
		else{
			printf("Child PID :%jd\n", (intmax_t)getpid());
			sleep(2);
		}
			
	}
	else{
		printf("Parent PID:%jd\n", (intmax_t)getpid());
		sleep(2);
		pid = fork();
		if(pid<0){
			printf("Third Fork is not working");
			return 1;
		}
		else if(pid==0){
			printf("new Child PID:%jd\n",(intmax_t)getpid());
			printf("Parent PID: %jd\n",(intmax_t)getppid());
		}
		else{
			printf("Parent PID:%jd\n",(intmax_t)getpid());
			sleep(2);
		}
	}
	return 0;
}

