#include<stdio.h>
#include<stdlib.h>
int f, p, seq[30];
int distance(int start, int val)
{
    int dist = 0;
    for(int k=start; k>=0; k--)
    {
        dist--;
        if(seq[k]==val)
        {
            break;
        }
    }
    return dist;
}
int main()
{
    int m[30], flag = 0, rear = 0, max = 0, temp = 0, pos = 0;
    int faults = 0;
    printf("enter the number of frames:");
    scanf("%d", &f);
    printf("enter the number of page:");
    scanf("%d", &p);
    printf("enter the pages:\n");
    for(int i=0; i<p; i++)
    {
        scanf("%d", &seq[i]);
    }
    for(int i=0; i<p; i++)
    {
        if(rear==f)
        {
            for(int j=0; j<f; j++)
            {
                if(m[j]==seq[i])
                {
                    flag = 1;
                }
            }
            if(flag==0)
            {
                faults = faults + 1;
                for(int j=0; j<f; j++)
                {
                    temp = distance(i,m[j]);
                    if(temp<max)
                    {
                        max = temp;
                        pos = j;
                    }
                }
                m[pos] = seq[i];
                max = 0;
                pos = 0;
            }
            flag = 0;
        }
        else
        {
            for(int j=0; j<rear; j++)
            {
                if(m[j]==seq[i])
                {
                    flag = 1;
                }
            }
            if(flag==0)
            {
                faults = faults + 1;
                m[rear] = seq[i];
                rear = rear + 1;
            }
            flag = 0;
        }
    }
    printf("\n number of page fault is: %d", faults);
    return 0;
}