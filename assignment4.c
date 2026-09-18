#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	pid_t pid=fork();
	if(pid<0) return 1;
	if(pid==0){
		execl("/bin/grep","grep","-win","խաղալիք","test.txt",NULL);
		perror("faled");
		return 1;
	}
	else{
		waitpid(pid,NULL,0);
		printf("Parent process done: \n");
	}
	return 0;
}
