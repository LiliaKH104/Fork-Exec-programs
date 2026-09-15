#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	printf("Before 1st fork\n");
        fork();
	printf("After 1st fork\n");

        fork();
	printf("After 2nd fork\n");

        fork();
	printf("After 3rd fork\n");


        return 0;
}
