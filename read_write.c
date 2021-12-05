#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
int n_readers= 0;
sem_t reader;
sem_t writer;
void* write_routine(void *args)
{
while(1)
{
sem_wait(&writer);
printf("Writer: Writing to file...\n");
usleep(2000);
sem_post(&writer);
}
}
void* read_routine(void *args)
{
while(1)
{
sem_wait(&reader);
n_readers++;
if(n_readers==1)
{
sem_wait(&writer);
}
sem_post(&reader);
printf("Reader: Reading the file...\n");
usleep(1000);
sem_wait(&reader);
n_readers--;
if(n_readers==0)
{
sem_post(&writer);
}
sem_post(&reader);
}
}
int main()
{
int n;
scanf("%d", &n);
sem_init(&writer,0, 1);
sem_init(&reader, 0, 1);
pthread_t t[10];
int i;
for(i=0;i<2+n;i++)
{
if(i>0)
{
if(pthread_create(t+i, NULL, &write_routine, NULL)!=0)
{
perror("Failed to create writer thread");
}
}
else
{
if(pthread_create(t+i, NULL, &read_routine, NULL)!=0)
{
perror("Failed to create reader thread");
}
}
}
for(i=0;i<2+n;i++){
if(pthread_join(t[i],NULL)!=0)
{
perror("Failed to join the threads");
}
}
sem_destroy(&reader);
sem_destroy(&writer);
return 0;
}