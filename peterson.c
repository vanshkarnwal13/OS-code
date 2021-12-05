#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
#define max 10
#define true 1
#define false 0
#define p1 0
#define p2 1
int buffer[max];
int rear = -1;
int interested[2];
int turn;
clock_t strt;

void entrySection(int process);
void endSection(int process);
void *producer(void *);
void *consumer(void *);
void bufferdisplay();

int main(){
    pthread_t t1; 
    pthread_t t2; 
    interested[0] = 0;
    interested[1] = 0;
    strt = clock();
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL); 
    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    return 0;
}

void produce(int item)
{
	if(rear==max-1)
		printf("can't produced it.\n");
    else{
	    buffer[++rear]=item;
	    clock_t executetime=clock();
	    double clk =(double)((executetime-strt)/CLOCKS_PER_SEC);
	    printf("%d is produced at time %.4f sec.\n",item,clk);
	    bufferdisplay();
	    if(clk>60)
	        exit(0);
    }
}

void consume(){
    if(rear<0)
        printf("no item to consume\n");
    else
    {
        int i;
        int item = buffer[0];
        for(i=0; i<rear;i++)
            buffer[i] = buffer[i+1];
        rear--;
        sleep(item);
        clock_t executetime = clock();
        double clk = (double)((executetime - strt)/CLOCKS_PER_SEC);
        printf("%d is consumed at time %.2f sec.\n",item,clk);
	    bufferdisplay();
	    if(clk>60)
	        exit(0);
    }
    
}

void bufferdisplay(){
    int i;
    if(rear < 0)
        printf("no buffer can be display\n\n");
    else
    {
        printf("buffers: ");
        for(i=0; i<=rear; i++)
            printf("%d\t", buffer[i]);
        printf("\n\n");
    } 
}

void *producer(void *arg){
    do{
        entrySection(p2);
        produce(rand()%10);
        endSection(p2);
    }while(turn == p2);
}

void *consumer(void *arg){
    do
    {
        entrySection(p1);
        consume();
        endSection(p1);
    } while (turn == p1);
    
}

void entrySection(int process){
    int other;
    other = 1- process;
    interested[process] = true;
    turn = other; 
    while (interested[other] == true && turn == other);
}

void endSection(int process){
    interested[process] = false;
}