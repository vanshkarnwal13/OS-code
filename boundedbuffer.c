#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<time.h>
sem_t empty;
sem_t full;
pthread_mutex_t mutexBuffer = PTHREAD_MUTEX_INITIALIZER;
int buffer[10000];

int count = 0;
void* producer(void* args)
{
while(1){
int x;
sem_wait(&empty);
pthread_mutex_lock(&mutexBuffer);
printf("Producer: Add value:");
scanf("%d", &x);
buffer[count] = x;
count++;
printf("Added value: %d", x);
pthread_mutex_unlock(&mutexBuffer);
sem_post(&full);
// return NULL;
}
}
void* consumer(void* args)
{
while(1){
int y;
sem_wait(&full);
pthread_mutex_lock(&mutexBuffer);
y = buffer[count-1];
count--;
pthread_mutex_unlock(&mutexBuffer);
sem_post(&empty);
printf("Consumer: Removed %d\n", y);
// return NULL;
}
}
int main()
{
int n, i;
scanf("%d", &n);
pthread_t t[4];
srand(time(NULL));
sem_init(&empty, 0, n);
sem_init(&full, 0, 0);
for(i=0; i<4; i++)
{
if(i>2)
{
if(pthread_create(t+i, NULL, &producer, NULL)!=0)
{
perror("Failed to create producer");
}
}
else
{
if(pthread_create(t+i, NULL, &consumer, NULL)!=0)
{
perror("Failed to create consumer");
}
}
}
for(i=0;i<4;i++)
{
if(pthread_join(t[i], NULL)!=0)
{
perror("Failed to join the threads");
}
}
sem_destroy(&empty);
sem_destroy(&full);
pthread_mutex_destroy(&mutexBuffer);
return 0;
}