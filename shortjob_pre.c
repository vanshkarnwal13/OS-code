#include<stdio.h>
int main(){
    int n,tt,at[10],bt[10],rbt[10],ct[10],as[10],cs[10],wt[10],tat[10];
    int tm[25],proc[25];
    int ind=0;
    printf("Enter total number of processes(maximum 10):");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        printf("\nEnter  arrival Time for process %d: ",i+1);
        scanf("%d",&at[i]);
        printf("\nEnter Burst Time for process %d: ",i+1);
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<25;i++){
        tm[i]=0;
        proc[i]=0;
    }

    for(int i=0;i<n;i++){
        as[i]=0;
        cs[i]=0;
        rbt[i]=bt[i];
        ct[i]=0;
        
    }
    int min=at[0];
    int curr;
    for(int i=0;i<n;i++){
        if(at[i]<min){
            min=at[i];
            curr=i;
        }
    }
    tt=at[curr];
    tm[ind]=tt;
    as[curr]=1;
    int cp=0;
    while(cp!=n){
        ind++;
        int min_at=999;
        int flag=0;
        int temp=-1;
        for(int i=0;i<n;i++){
            if(as[i]==0){
                if(at[i]<min_at){
                    min_at=at[i];
                    temp=i;
                }
            flag++;   
            }
        }
        if(flag>0){
            rbt[curr]=rbt[curr]+tt-at[temp];
            if(rbt[curr]>=0){
                tt=at[temp];
                as[temp]=1;
            }
            else{
                tt=at[temp]+rbt[curr];
                rbt[curr]=0;
                cs[curr]=1;
                ct[curr]=tt;
            }
        }
        else{
            tt+=rbt[curr];
            rbt[curr]=0;
        }
        if(rbt[curr]==0){
            cs[curr]=1;
            ct[curr]=tt;
        }
        proc[ind-1]=curr;
        tm[ind]=tt;
        int min_bt=999;
        flag=0;
        for(int i=0;i<n;i++){
            if(cs[i]==0){
                if(as[i]==1){
                    if(rbt[i]<min_bt){
                        min_bt=rbt[i];
                        curr=i;
                        flag++;
                    }
                }
            }
        }
        curr=curr;
        cp=0;
        for(int i=0;i<n;i++){
            cp+=cs[i];
        }
    }
    printf("Execution order from Gantt chart:");
    for(int i=0;i<ind+1;i++){
        int k=0;
        while(k<(tm[i+1]-tm[i])){
            k=k+1;
            printf("P%d ",proc[i]+1);
        }
    }
    int sum_wt=0;
    int sum_tat=0;
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        sum_tat+=tat[i];
        sum_wt+=wt[i];
    }
    
    for(int i=0;i<n;i++){
        printf("\nWT of P%d :",i+1);
        printf("%d",wt[i]);
        
    }
    
    for(int i=0;i<n;i++){
        printf("\nTAT of P%d :",i+1);
        printf("%d",tat[i]);
        
    }
    
    
    printf("\naverage turn around time:%0.2f\n",sum_tat/(float)n);
    printf("average waiting time:%0.2f",sum_wt/(float)n);
    return 0;
}