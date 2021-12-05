#include<stdio.h>
int main(){
    int n,at[20],pr[20],bt[20],rt[20],eo[20],et[20],tat[20],wt[20],spr[20],feo[20];
    int fp=0;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
    printf("\nEnter Process arrival Time\n");
    for(int i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    int min=at[0];
    for(int i=0;i<n;i++){
        if(at[i]<min){
            min=at[i];
            fp=i;
        }
    }
    eo[0]=fp;
    printf("\nEnter Process priority(least number more priority)\n");
    for(int i=0;i<n;i++){
        scanf("%d",&pr[i]);
    }
    printf("\nEnter Process Burst Time\n");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    int temp;
    for(int i=0;i<n;i++){
        spr[i]=pr[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(spr[j]>spr[j+1]){
                temp=spr[j+1];
                spr[j+1]=spr[j];
                spr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        //printf("%d ",spr[i]);
    }
    //printf("\n");
    int p=1;
    int flag=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(spr[i]==pr[fp]){
            count++;
        }
    }
    for(int i=0;i<n;i++){
        if(count>1){
            if(spr[i]==pr[fp]){
                flag++;
                }
        }
        for(int j=0;j<n;j++){
            if(j!=fp && flag!=1){
                    if(pr[j]==spr[i]){
                        eo[p]=j;
                        p++;
                    }
                }
            }
        }
    eo[0]=fp;
    int time=at[0];
    for(int i=0;i<n;i++){
        feo[i]=eo[i];
    }
    for(int i=0;i<n-1;i++){
        time = time + bt[feo[i]];
        int k =i+1;
        while(time<at[eo[k]]){
            feo[k+1]= eo[k];
            k++;
        }
        feo[i+1]=eo[k];
        for(int j=0;i<n;i++){
            feo[j]=eo[j];            
        }
    }
    for( int i=0;i<n;i++){
        //printf("%d ",feo[i]);
    }
    //printf("\n");
    et[feo[0]]=bt[feo[0]]+at[feo[0]];
    //printf("%d ",et[feo[0]]);
    for(int i=1;i<n;i++){
        et[feo[i]]=bt[feo[i]]+et[feo[i-1]];
        //printf("%d ",et[feo[i]]);
    }
    //printf("\n");
    int sumtat=0;
    int sumwt=0;
    printf("turn aroune time:\n");
    for(int i=0;i<n;i++){
        tat[i]=et[i]-at[i];
        printf("%d\n",tat[i]);
        sumtat=sumtat+tat[i];
    }
    
    printf(" waiting time:\n");
    for(int i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        printf("%d\n",wt[i]);
        sumwt=sumwt+wt[i];
    }
    printf("response time:\n");
    for(int i=0;i<n;i++){
        rt[i]=et[i]-bt[i];
        printf("%d\n",rt[i]);
        
    }
    
    printf("average waiting time:%.2f\n",sumwt/(float)n);
    printf("average turn around time:%.2f\n",sumtat/(float)n);
    
    return 0;
}