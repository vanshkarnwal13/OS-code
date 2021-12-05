#include<stdio.h>
#include<stdlib.h>
int req[30];
int schedule_scan(int n, int start, int max)
{
    int seek = 0;
    int temp = 0, pos=0;  
    for(int i=0; i<n; i++)
    {
        if(req[i]==start)
        {
            pos = i;
        }
    }
    for(int i = pos-1; i>=0; i--)
    {
        seek = seek + abs(req[i]-start);
        start = req[i];
    }
    seek = seek + req[0]; 
    start = 0;
    for (int i = pos+1; i < n; i++)
    {
        seek = seek + abs(req[i]-start);
        start = req[i];        
    }
    // seek = seek + max - req[n-1];    
    return seek;
}
void sort(int n)
{
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(req[j]>req[j+1])
            {
                temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }        
    }
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
    
    req[n] = init;
    n++;        
    sort(n);

    
    seek = schedule_scan(n,init,max-1);
    printf("%d",seek);
    return 0;
}