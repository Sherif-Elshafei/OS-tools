#include <pthread.h>
#include <iostream>

/* x is a global variable to be updated by two different 
threads. Each thread has a separate function */
int x = 0;

void* threadFunction1(void* arg){
    for (int i=0;i<150000;i++){
        //Critical section
        pthread_mutex_lock((pthread_mutex_t*) arg);
        x++;
        pthread_mutex_unlock((pthread_mutex_t*) arg);
    }
    return NULL;
}

void* threadFunction2(void* arg){
    for (int i=0;i<5;i++){
        //Critical section
        pthread_mutex_lock((pthread_mutex_t*) arg);
        x++;
        pthread_mutex_unlock((pthread_mutex_t*) arg);
    }
    return NULL;
}

int main(){
    //Declare two threads
    pthread_t t1, t2;
    /* Declare and initialize a lock to the default 
    values and thus makes the lock usable */
    pthread_mutex_t lock1=PTHREAD_MUTEX_INITIALIZER;

    pthread_create(&t1, NULL, threadFunction1, &lock1);
    pthread_create(&t2, NULL, threadFunction2, &lock1);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    std::cout<<"x="<<x<<std::endl;
    return 0;
}