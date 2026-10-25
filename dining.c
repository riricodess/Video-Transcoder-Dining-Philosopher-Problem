#include <stdio.h>
#include <pthread.h>

pthread_mutex_t locks[2];

void *transcode(void *arg)
{
    int id = *(int *)arg;

    pthread_mutex_lock(&locks[id]);
    pthread_mutex_lock(&locks[(id + 1) % 2]);

    printf("Transcoder Thread %d: Acquired locks & processing frame.\n", id);

    pthread_mutex_unlock(&locks[(id + 1) % 2]);
    pthread_mutex_unlock(&locks[id]);

    return NULL;
}

int main(void)
{
    int id;
    pthread_t thread;

    if (pthread_mutex_init(&locks[0], NULL) != 0 ||
        pthread_mutex_init(&locks[1], NULL) != 0) {
        fprintf(stderr, "Failed to initialize mutex locks.\n");
        return 1;
    }

    printf("Enter worker ID (0 or 1): ");
    if (scanf("%d", &id) != 1 || id < 0 || id > 1) {
        fprintf(stderr, "Invalid worker ID. Enter 0 or 1.\n");
        pthread_mutex_destroy(&locks[0]);
        pthread_mutex_destroy(&locks[1]);
        return 1;
    }

    if (pthread_create(&thread, NULL, transcode, &id) != 0) {
        fprintf(stderr, "Failed to create transcoder thread.\n");
        pthread_mutex_destroy(&locks[0]);
        pthread_mutex_destroy(&locks[1]);
        return 1;
    }

    pthread_join(thread, NULL);

    pthread_mutex_destroy(&locks[0]);
    pthread_mutex_destroy(&locks[1]);

    return 0;
}
