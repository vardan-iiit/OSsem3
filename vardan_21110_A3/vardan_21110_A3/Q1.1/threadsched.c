#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>
#include<sched.h>

void* countA(){

    int policy=SCHED_OTHER;
    struct sched_param param;
    param.sched_priority=0;

    int s=pthread_setschedparam(pthread_self(),policy,&param);

    for(unsigned long int i=1;i<4294967296;++i){

    }
    pthread_exit(NULL);
}
void* countB(){

     int policy=SCHED_RR;
    struct sched_param param;
    param.sched_priority=50;

    int s=pthread_setschedparam(pthread_self(),policy,&param);

    for(unsigned long int j=1;j<4294967296;++j){

    }
    pthread_exit(NULL);

}
void* countC(){

     int policy=SCHED_FIFO;
    struct sched_param param;
    param.sched_priority=60;

    int s=pthread_setschedparam(pthread_self(),policy,&param);

    for(unsigned long int k=1;k<4294967296;++k){

    }
    pthread_exit(NULL);

}


int main(){
    pthread_t tA,tB,tC;

    FILE *fis;
    fis=fopen("elapse.txt","w");
    struct timespec beforeA;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&beforeA);
    pthread_create(&tA,NULL,countA,NULL);
    struct timespec afterA;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&afterA);
    pthread_join(tA,NULL);

    double elapseA=(int)(afterA.tv_nsec-beforeA.tv_nsec);
    char t[50];
    sprintf(t,"%lf\n",elapseA);
    fputs(t,fis);


    struct timespec beforeB;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&beforeB);
    pthread_create(&tB,NULL,countB,NULL);
    struct timespec afterB;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&afterB);
    pthread_join(tB,NULL);

    double elapseB=(double)(afterB.tv_nsec-beforeB.tv_nsec);
    char tt[50];
    sprintf(tt,"%lf\n",elapseB);
    fputs(tt,fis);



    struct timespec beforeC;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&beforeC);
    pthread_create(&tC,NULL,countC,NULL);
    struct timespec afterC;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&afterC);
    pthread_join(tC,NULL);

    double elapseC=(double)(afterC.tv_nsec-beforeC.tv_nsec);
    char ttt[50];
    sprintf(ttt,"%lf\n",elapseC);
    fputs(ttt,fis);




    return 0;
}
