#include<stdio.h>
int main(){
    int n,tt,at[10],bt[10],rbt[10],ct[10],as[10],cs[10],wt[10],tat[10];
    printf("Enter total number of processes(maximum 10):");
    scanf("%d",&n);
    
    for(int pi=0;pi<n;pi++){
        printf("\nEnter  arrival Time for process %d",pi);
        scanf("%d",&at[pi]);
        printf("\nEnter Burst Time for process %d",pi);
        scanf("%d",&bt[pi]);
    }
    
}