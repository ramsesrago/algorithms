#include <iostream>
#include <pthread.h>

// Macro for thread names
// #define TASK(taskname) 	void* task##tasknumber(void*)

void* task1(void*) {
    // Get the tid and name from the current context
    // pthread_t thread = pthread_self();
    // char threadName[10];
    // pthread_getname_np(thread, threadName);
    // std::cout << "Hello my thread name is: " << threadName << std::endl;
    return NULL;
}

void* task2(void*) {
    // Get the tid and name from the current context
    // pthread_t thread = pthread_self();
    // char threadName[10];
    // pthread_getname_np(thread, threadName);
    // std::cout << "Hello my thread name is: " << threadName << std::endl;
    return NULL;
}

int main() {
    std::cout << "Main, starting program" << std::endl;
    
    // Creating thread objects
    pthread_t thread1;
    pthread_t thread2;
    
    // This will link thread1 with task1 and run automatically
    pthread_create(&thread1, NULL, &task1, NULL);
    pthread_create(&thread2, NULL, &task2, NULL);

    // Set the thread names
    // pthread_setname_np(thread1, "Task 1");
    // pthread_setname_np(thread2, "Task 2");

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
     
    return 0;
}