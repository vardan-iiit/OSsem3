#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char **argv){
char *binary="/bin/mkdir";
execl(binary,binary,argv[1],argv[2],NULL);
return 0;
}
