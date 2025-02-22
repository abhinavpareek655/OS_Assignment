#include <stdio.h>
#include <pthread.h>

int account_balance = 1000;
pthread_mutex_t lock;

void* transaction(void* amount) {
    int *amt = (int*)amount;

    pthread_mutex_lock(&lock); // Lock the mutex
    account_balance += *amt;
    printf("Transaction: %d, New Balance: %d\n", *amt, account_balance);
    pthread_mutex_unlock(&lock); // Unlock the mutex

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    int amounts[2] = {200, -100};

    pthread_mutex_init(&lock, NULL); // Initialize the mutex

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, transaction, (void*)&amounts[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock); // Destroy the mutex
    printf("Final Account Balance: %d\n", account_balance);
    return 0;
}