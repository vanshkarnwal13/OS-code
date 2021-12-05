#include<stdio.h>
#include<stdlib.h>
int req[30];
int schedule_fcfs(int n, int start)
{
    int seek = 0;
    for(int i=0; i<n; i++)
    {
        seek = seek + abs(req[i]-start);
        start = req[i];
    }
    return seek;
}
int main()
{
    int seek;
    int n, init, max=200;
    scanf("%d", &init);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&req[i]);
    }
    seek = schedule_fcfs(n,init);
    
    printf("%d",seek);
    return 0;
}