#include<stdio.h>
#include<unistd.h>
void main(int argc, char **argv){

	char* binary="/bin/date";

	execl(binary,binary,argv[1],NULL);
	return;

}
