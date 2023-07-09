#include<stdio.h>
#include<unistd.h>
void main(int argc, char **argv){

	char* binary="/bin/rm";

	execl(binary,binary,argv[1],argv[2],NULL);
	return;

}
