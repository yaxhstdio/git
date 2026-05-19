#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t chopstick[5];

void* philosopher(void* num) {
    int id = *(int*)num;
    int left = id;
    int right = (id + 1) % 5;

    // Deadlock Prevention: The "Left-Handed" Philosopher
    if (id == 4) {
        pthread_mutex_lock(&chopstick[right]);
        pthread_mutex_lock(&chopstick[left]);
    } else {
        pthread_mutex_lock(&chopstick[left]);
        pthread_mutex_lock(&chopstick[right]);
    }

    printf("Philosopher %d is Eating\n", id);
    sleep(1); 

    pthread_mutex_unlock(&chopstick[left]);
    pthread_mutex_unlock(&chopstick[right]);

    printf("Philosopher %d finished Eating and is Thinking\n", id);
    return NULL;
}

int main() {
    pthread_t ph[5];
    int i, id[5];

    for (i = 0; i < 5; i++) pthread_mutex_init(&chopstick[i], NULL);

    for (i = 0; i < 5; i++) {
        id[i] = i;
        pthread_create(&ph[i], NULL, philosopher, &id[i]);
    }

    for (i = 0; i < 5; i++) pthread_join(ph[i], NULL);

    return 0;
}