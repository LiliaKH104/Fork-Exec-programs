#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        return 1;
    }
    else if (pid == 0) {
        printf("Child\n");

        execl("/bin/ls", "ls", NULL);
        return 1;
    }
    else {
        waitpid(pid, NULL, 0);
        printf("Parent process done\n");
    }

    return 0;
}

