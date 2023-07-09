#include<unistd.h>
#include<stdio.h>
int main(int argc, char **argv){
 char *binary="/bin/ls";
 
 execl(binary,binary,argv[1],NULL);
 return 0;


}
