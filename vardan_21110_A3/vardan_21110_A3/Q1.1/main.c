#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sched.h>
#include<pthread.h>
#include<unistd.h>

void* countA(){

    struct sched_param schedparam;
    schedparam.sched_priority=0;
    pthread_setschedparam(pthread_self(),SCHED_OTHER,&schedparam);
    unsigned long int i;
    
    for(i=1;i<4294967296;++i){

    }
    pthread_exit(NULL);
}

void* countB(){

    struct sched_param schedparam;
    schedparam.sched_priority=30;
    pthread_setschedparam(pthread_self(),SCHED_RR,&schedparam);
    unsigned long int i;
    
    for( i=1;i<4294967296;++i){
        
    }
    pthread_exit(NULL);
}

void* countC(){

    struct sched_param schedparam;
    schedparam.sched_priority=40;
    pthread_setschedparam(pthread_self(),SCHED_FIFO,&schedparam);
    unsigned long int i;
    
    for( i=1;i<4294967296;++i){
         
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    FILE *ftr;
    ftr=fopen("ans.txt","w");
    

    
    struct timespec start1, start2, start3, finish1,finish2,finish3;    
    double elapsed;
    double e;
    double el;

    clock_gettime(CLOCK_MONOTONIC, &start1);
    pthread_create(&t1,NULL,&countA,NULL);
    clock_gettime(CLOCK_MONOTONIC, &finish1);
    elapsed = (finish1.tv_nsec - start1.tv_nsec);
    
    char a[50];
    sprintf(a,"%lf\n",elapsed);
    fputs(a,ftr);



    clock_gettime(CLOCK_MONOTONIC, &start2);
    pthread_create(&t2,NULL,&countB,NULL);
    clock_gettime(CLOCK_MONOTONIC, &finish2);
    e = (finish2.tv_nsec - start2.tv_nsec);

    char t[50];
    sprintf(t,"%lf\n",e);
    fputs(t,ftr);
   

    

    clock_gettime(CLOCK_MONOTONIC, &start3);
    pthread_create(&t3,NULL,&countC,NULL);
    clock_gettime(CLOCK_MONOTONIC, &finish3);
    el = (finish3.tv_nsec - start3.tv_nsec);

    char p[50];
    sprintf(p,"%lf\n",el);
    fputs(p,ftr);
    
   
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
   
    
return 0;
   

}
