#include<stdio.h>


int main()
{
    int n,i;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
    int at[20],bt[20],sta[20],ct[20],wt[20],tat[20];
    int v[20];
    printf("\nEnter Process arrival Time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
        v[i]=0;
    }

    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    printf("\n");
    int j;
    int sum=at[0];
    for(i=1;i<n;i++)
    {
        if(at[i]<sum)
        {
            sum=at[i];
        }
    }
    
    int idx;
    int cp=0;
    while(cp<n)
    {
       
       int min_bt=999;
       for(j=0;j<n;j++)
        {
            if(at[j]<=sum && v[j]==0)
            {
                if(bt[j]<min_bt)
                {
                    min_bt=bt[j];
                    idx=j;
                }
            }    
        }    
        sum=sum+min_bt;
        

        ct[idx]=sum;
        v[idx]=1;
        cp=cp+1;

    }
    float avg_tat=0,avg_wt=0;
    printf("turn aroune time:");
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        avg_tat=avg_tat+tat[i];
        printf("%d\n",tat[i]);
        

    }
    
    printf("average turn around time:%f",avg_tat*1.0/n);
    printf("\n");
    printf("average waiting time:");
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        avg_wt=avg_wt+wt[i];
        printf("%d\n",wt[i]);
        
    }
    
    printf("average waiting time:%f",avg_wt*1.0/n);
    return 0;
    
    
}