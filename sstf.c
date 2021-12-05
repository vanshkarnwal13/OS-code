#include<stdio.h>
#include<stdlib.h>
int req[30];
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
    seek = schedule_sstf(n,init,max-1);   
    printf("%d",seek);
    return 0;
}