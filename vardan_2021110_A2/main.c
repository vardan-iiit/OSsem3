#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define BUFFER_LEN 1024
#include<pthread.h>


//lscommand using threads
void* lscommand(void *arg){
	char com[]="./ls ";
	char *str=(char*)arg;

	strcat(com,str);
	char *arg1=com;

	system(arg1);
	pthread_exit(NULL);
}
void* datecommand(void *arg){
	char com[]="./date ";
	char *str=(char*)arg;

	strcat(com,str);
	char *arg1=com;

	system(arg1);
	pthread_exit(NULL);
}
void* mkdircommand(void *arg){
	char com[]="./mkdir ";
	char *str=(char*)arg;

	strcat(com,str);
	char *arg1=com;

	system(arg1);
	pthread_exit(NULL);
}
void* rmcommand(void *arg){
	char com[]="./rm ";
	char *str=(char*)arg;

	strcat(com,str);
	char *arg1=com;

	system(arg1);
	pthread_exit(NULL);
}
void* catcommand(void *arg){
	char com[]="./cat ";
	char *str=(char*)arg;

	strcat(com,str);
	char *arg1=com;

	system(arg1);
	pthread_exit(NULL);
}


int main(){



while(1){
	printf(">>> ");
	char line[BUFFER_LEN];
	char* argv[100];
	int argc;
	fgets(line,BUFFER_LEN,stdin);
		
	
	if(strcmp(line,"exit\n")==0){
		break;
		
	}
	char *token;
	token = strtok(line," ");
	int i=0;
	while(token!=NULL){
		argv[i]=token;
		token=strtok(NULL," ");
		i++;
	}

	argc=i;


	if(strcmp(argv[0],"&t")==0){
		pthread_t t1;
		//ls command
		if(strcmp(argv[1],"ls")==0){

			if(strcmp(argv[2],"-a\n")==0 || strcmp(argv[2],"-l\n")==0){
				pthread_create(&t1,NULL,&lscommand,argv[2]);
				pthread_join(t1,NULL);
			}
			else if(strcmp(argv[2],"\n")==0){
				char *ss="";
				pthread_create(&t1,NULL,&lscommand,ss);
				pthread_join(t1,NULL);

			}
			else{
				printf("this command is not supported\n");
			}

		}

			//date command
		else if(strcmp(argv[1],"date")==0){

			if(strcmp(argv[2],"+%y\n")==0 || strcmp(argv[2],"+%B\n")==0){
				pthread_create(&t1,NULL,&datecommand,argv[2]);
				pthread_join(t1,NULL);
			}
			else if(strcmp(argv[2],"\n")==0){
				char *sa="";
				pthread_create(&t1,NULL,&datecommand,sa);
				pthread_join(t1,NULL);

			}
			else{
				printf("this command is not supported\n");
			}

		}

				//mkdir command
		else if(strcmp(argv[1],"mkdir")==0){

			if(strcmp(argv[2],"\n")){
				printf("Error : no name specified\n");
			}
			else{
				if(strcmp(argv[2],"-v")==0){

					if(strcmp(argv[3],"\n")){
						printf("Error : no name specified\n");
					}
					else{
						char arg[100]="-v ";
						strcat(arg,argv[3]);
						arg[strlen(arg)-1]=0;
						pthread_create(&t1,NULL,&mkdircommand,arg);
						pthread_join(t1,NULL);

					}


				}
				else if(strcmp(argv[2],"-p")==0){

					if(strcmp(argv[3],"\n")){
						printf("Error : no name specified\n");
					}
					else{
						char arg[100]="-p ";
						strcat(arg,argv[3]);
						arg[strlen(arg)-1]=0;
						pthread_create(&t1,NULL,&mkdircommand,arg);
						pthread_join(t1,NULL);
					}





				}

				else{
					char arg[100]="";
					strcat(arg,argv[2]);
					arg[strlen(arg)-1]=0;

					pthread_create(&t1,NULL,&mkdircommand,arg);
					pthread_join(t1,NULL);

				}
			}


		}

					//rm command
		else if(strcmp(argv[1],"rm")==0){

			if(strcmp(argv[2],"-i")==0){

				char arg[100]="-i ";
				strcat(arg,argv[3]);
				arg[strlen(arg)-1]=0;
				pthread_create(&t1,NULL,&rmcommand,arg);
				pthread_join(t1,NULL);

			}
			else if(strcmp(argv[2],"-f")==0){

				char arg[100]="-f ";
				strcat(arg,argv[3]);
				arg[strlen(arg)-1]=0;
				pthread_create(&t1,NULL,&rmcommand,arg);
				pthread_join(t1,NULL);



			}

			else{
				char arg[100]="";
				strcat(arg,argv[2]);
				arg[strlen(arg)-1]=0;

				pthread_create(&t1,NULL,&rmcommand,arg);
				pthread_join(t1,NULL);

			}
		}


					//cat command
		else if(strcmp(argv[1],"cat")==0){

			if(strcmp(argv[2],"-A")==0){

				char arg[100]="-A ";
				strcat(arg,argv[3]);
				arg[strlen(arg)-1]=0;
				pthread_create(&t1,NULL,&catcommand,arg);
				pthread_join(t1,NULL);

			}
			else if(strcmp(argv[2],"-b")==0){

				char arg[100]="-b ";
				strcat(arg,argv[3]);
				arg[strlen(arg)-1]=0;
				pthread_create(&t1,NULL,&catcommand,arg);
				pthread_join(t1,NULL);



			}

			else{
				char arg[100]="";
				strcat(arg,argv[2]);
				arg[strlen(arg)-1]=0;

				pthread_create(&t1,NULL,&catcommand,arg);
				pthread_join(t1,NULL);

			}
		}
	}
	else{


	///FORK EXEC SHELL
	pid_t n;
	n=fork();
	if(n<0){
	printf("\nFork Error\n");
	}
	else if(n==0){
		
		//ls command
		if(strcmp(argv[0],"ls")==0){
		
			if(strcmp(argv[1],"-l\n")==0){
				
				char *arg1[]={"./ls","-l",NULL};
			
				execv("./ls",arg1);
			}
			else if(strcmp(argv[1],"-a\n")==0){
			
				char *arg1[]={"./ls","-a",NULL};
				execv("./ls",arg1);

			}
			else if(strcmp(argv[1],"\n")==0){
				char *arg1[]={"./ls",NULL};
				execv("./ls",arg1);
			
			}
			else{
			printf("Sorry!! only ls, ls -a and ls -l are supported\n");
			}
		}
				//cd command(handled internally)
		else if(strcmp(argv[0],"cd")==0){

				char arg[100]="";
				strcat(arg,argv[1]);
				arg[strlen(arg)-1]=0;

				chdir(arg);




		}
		//echo command
		else if(strcmp(argv[0],"echo")==0){
			if(strcmp(argv[1],"-E")==0){

				char arg[100]="";
				for(int u=2;u<argc;u++){
					strcat(arg," ");
					strcat(arg,argv[u]);
			         }
				arg[strlen(arg)-1]=0;
				char *arg1[]={"./echo","-E",arg,NULL};

						execv("./echo",arg1);

			
			}
			else if(strcmp(argv[1],"-n")==0){
				char arg[100]="";
				for(int u=2;u<argc;u++){
					strcat(arg," ");
					strcat(arg,argv[u]);
				}
				arg[strlen(arg)-1]=0;
					char *arg1[]={"./echo","-n",arg,NULL};

						execv("./echo",arg1);
				
			}
			else{

				char arg[100]="";

			for(int g=1;g<argc;g++){
			    strcat(arg," ");
			    strcat(arg,argv[g]);


			}
			arg[strlen(arg)-1]=0;
			char *arg1[]={"./echo",arg,NULL};




			execv("./echo",arg1);
			}

		
		}
		//mkdir command
		else if(strcmp(argv[0],"mkdir")==0){

			if(strcmp(argv[1],"-v")==0){
				
				char arg[100]="";
				strcat(arg,argv[2]);
				arg[strlen(arg)-1]=0;
				char *arg1[]={"./mkdir","-v",arg,NULL};
				execv("./mkdir",arg1);	
			}
			else if(strcmp(argv[1],"-p")==0){

				char arg[100]="";
				strcat(arg,argv[2]);
				arg[strlen(arg)-1]=0;
				char *arg1[]={"./mkdir","-p",arg,NULL};
				execv("./mkdir",arg1);
			
			}

			else{ 
				char arg[100]="";
			
				strcat(arg,argv[1]);
				arg[strlen(arg)-1]=0;
		 	 
				char *arg1[]={"./mkdir",arg,NULL};
				execv("./mkdir",arg1);
			}
		}

		//pwd command
		else if(strcmp(argv[0],"pwd")==0){
			char ss[100];
			printf("%s\n",getcwd(ss,100));
		}

				//date command
		else if(strcmp(argv[0],"date")==0){

			if(strcmp(argv[1],"+%y\n")==0){

				char arg[100]="";
				strcat(arg,argv[1]);
				arg[strlen(arg)-1]=0;

				char * arg1[]={"./date",arg,NULL};
			    execv("./date",arg1);

			}

			else if(strcmp(argv[1],"+%B\n")==0){

				char arg[100]="";
				strcat(arg,argv[1]);
				arg[strlen(arg)-1]=0;

				char * arg1[]={"./date",arg,NULL};
			    execv("./date",arg1);

			}

			else if(strcmp(argv[1],"\n")==0){
				char * arg1[]={"./date",NULL};
				execv("./date",arg1);
			}
			else{
				printf("sorry this command is not supported by the shell\n");
			}
		}

		//rm command
		else if(strcmp(argv[0],"rm")==0){

			if(strcmp(argv[1],"-i")==0){

				char arg[100]="";
				strcat(arg,argv[2]);
				arg[strlen(arg)-1]=0;
				char *arg1[]={"./rm","-i",arg,NULL};
				execv("./rm",arg1);
			}
			else if(strcmp(argv[1],"-f")==0){

				char arg[100]="";
				strcat(arg,argv[2]);
				arg[strlen(arg)-1]=0;
				char *arg1[]={"./mkdir","-p",arg,NULL};
				execv("./mkdir",arg1);

			}

			else{
				char arg[100]="";

				strcat(arg,argv[1]);
				arg[strlen(arg)-1]=0;

				char *arg1[]={".rm",arg,NULL};
				execv("./rm",arg1);
			}
		}

		//cat command

		else if(strcmp(argv[0],"cat")==0){

			if(strcmp(argv[1],"-A")==0){

				char arg[100]="";
				strcat(arg,argv[2]);
				arg[strlen(arg)-1]=0;
				char *arg1[]={"./cat","-A",arg,NULL};
				execv("./cat",arg1);
			}
			else if(strcmp(argv[1],"-b")==0){

				char arg[100]="";
				strcat(arg,argv[2]);
				arg[strlen(arg)-1]=0;
				char *arg1[]={"./cat","-b",arg,NULL};
				execv("./cat",arg1);

			}

			else{
				char arg[100]="";

				strcat(arg,argv[1]);
				arg[strlen(arg)-1]=0;

				char *arg1[]={"./cat",arg,NULL};
				execv("./cat",arg1);
			}
		}
		else{
			printf("This command is not supported by the shell\n");
		}

		


	
	}

	else{   wait(NULL);


	  }

    }
	
	


}
return 0;
}
