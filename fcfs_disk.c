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
int schedule_sstf(int n, int start, int max)
{
    int seek = 0;
    int min = max;
    int temp = 0, pos = 0;
    int rem = n;
    while(rem>0)
    {
        for(int i=0; i<n; i++)
        {
            if(req[i]!=-1)
            {
                temp = abs(req[i]-start);
                if(temp<min)
                {
                    min = temp;
                    pos = i;
                }
            }
        }
        seek = seek + min;
        start = req[pos];
        req[pos] = -1;
        rem = rem - 1;
        min = max;
    }
    return seek;
}
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
int schedule_look(int n, int start, int max)
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
    for (int i = pos+1; i < n; i++)
    {
        seek = seek + abs(req[i]-start);
        start = req[i];        
    }
    return seek;
}
int schedule_cscan(int n, int start, int max)
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
    seek = seek + max;
    start = max;
    for (int i = n-1; i>pos; i--)
    {
        seek = seek + abs(req[i]-start);
        start = req[i];        
    }
    return seek;
}
int schedule_clook(int n, int start, int max)
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
    start = req[0];
    for (int i = n-1; i >pos; i--)
    {
        seek = seek + abs(req[i]-start);
        start = req[i];        
    }
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
    int choice = 0;
    scanf("%d",&choice);
    scanf("%d", &max);
    scanf("%d", &init);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&req[i]);
    }
    if((choice>=3)&&(choice<=6))
    {
        req[n] = init;
        n++;        
        sort(n);

    }
    switch (choice)
    {
        case 1:
            seek = schedule_fcfs(n,init);
            break;
        case 2:
            seek = schedule_sstf(n,init,max-1);
            break;
        case 3:
            seek = schedule_scan(n,init,max-1);
            break;
        case 4:
            seek = schedule_look(n,init,max-1);
            break;
        case 5: 
            seek = schedule_cscan(n,init,max-1);
            break;
        case 6:
            seek = schedule_clook(n,init,max-1);
            break;
        default:
            printf("\nInvalid choice.");
    }
    printf("%d",seek);
    return 0;
}