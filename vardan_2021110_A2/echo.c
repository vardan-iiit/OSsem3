#include<unistd.h>
#include<stdio.h>
#include<string.h>
void main(int argc,char **argv){

char *binary="/bin/echo";

execl(binary,binary,argv[1],argv[2],NULL);
return;

}
