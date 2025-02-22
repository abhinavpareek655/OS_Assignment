#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For sleep()

int account1 = 1000;
int account2 = 1000;
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

// Thread 1: Transfer from account1 to account2
void* transfer1_to_2(void* arg) {
    int amount = *((int*)arg);
    
    if (&lock1 < &lock2) { 
        pthread_mutex_lock(&lock1);
        pthread_mutex_lock(&lock2);
    } else {
        pthread_mutex_lock(&lock2);
        pthread_mutex_lock(&lock1);
    }

    account1 -= amount;
    account2 += amount;
    printf("Thread 1: Transfer complete.\n");

    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

// Thread 2: Transfer from account2 to account1
void* transfer2_to_1(void* arg) {
    int amount = *((int*)arg);
    
    if (&lock1 < &lock2) { 
        pthread_mutex_lock(&lock1);
        pthread_mutex_lock(&lock2);
    } else {
        pthread_mutex_lock(&lock2);
        pthread_mutex_lock(&lock1);
    }

    account2 -= amount;
    account1 += amount;
    printf("Thread 2: Transfer complete.\n");

    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    int amount1 = 200;
    int amount2 = 300;

    // Create threads with conflicting lock orders
    pthread_create(&t1, NULL, transfer1_to_2, &amount1);
    pthread_create(&t2, NULL, transfer2_to_1, &amount2);

    // Wait for threads (they will never finish)
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final balances: Account1=%d, Account2=%d\n", account1, account2);
    return 0;
}