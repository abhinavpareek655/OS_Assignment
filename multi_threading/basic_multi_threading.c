#include <stdio.h>
#include <pthread.h>

int account_balance = 1000; // Shared account balance

void* transaction(void* amount) {
    int *amt = (int*)amount;
    account_balance += *amt;
    printf("Transaction: %d, New Balance: %d\n", *amt, account_balance);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    int amounts[2] = {200, -100}; // Deposit 200, Withdraw 100

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, transaction, (void*)&amounts[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final Account Balance: %d\n", account_balance);
    return 0;
}