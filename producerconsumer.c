// Race Condition - WITH Semaphore (Correct Synchronization)
// Producer increments count 100000 times
// Consumer decrements count 100000 times
// Final count value = 0

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int count = 0;          // Shared variable
sem_t mutex;            // Semaphore for mutual exclusion

// Producer Thread Function
void* producer(void* arg)
{
    for (int i = 0; i < 100000; i++)
    {
        sem_wait(&mutex);   // Acquire lock
        count++;            // Increment count
        sem_post(&mutex);   // Release lock
    }
    pthread_exit(NULL);
}

// Consumer Thread Function
void* consumer(void* arg)
{
    for (int i = 0; i < 100000; i++)
    {
        sem_wait(&mutex);   // Acquire lock
        count--;            // Decrement count
        sem_post(&mutex);   // Release lock
    }
    pthread_exit(NULL);
}

// Main Function
int main()
{
    pthread_t t1, t2;

    // Initialize semaphore with value 1 (binary semaphore)
    sem_init(&mutex, 0, 1);

    // Create two threads
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    // Wait for both threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy semaphore
    sem_destroy(&mutex);

    // Print final value of count
    printf("Final count value = %d\n", count);

    return 0;
}