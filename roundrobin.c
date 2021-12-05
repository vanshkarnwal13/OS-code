#include<stdio.h>
int main(){
    int n,tq,at[10],bt[10],rbt[10],as[10],cs[10],pct[10],nil[100],tt,wt[10],ct[10],tat[10];
    int cur=0,nxt=0;
    int pi;
    int cp=0;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
    printf("Enter sequence of ready queue:");
    scanf("%d",&tq);
    printf("\nEnter Process arrival Time\n");
    for(int pi=0;pi<n;pi++){
        scanf("%d",&at[pi]);
    }
    printf("\nEnter Process Burst Time\n");
    for(pi=0;pi<n;pi++){
        scanf("%d",&bt[pi]);
    }
    for(int pi=0;pi<n;pi++){
        as[pi]=0;
        rbt[pi]=bt[pi];
        cs[pi]=0;
    }
    for(int i=0;i<100;i++){
        nil[i]=-1;
    }
    int min_at=at[0];
    for(int pi=1;pi<n;pi++){
        if(at[pi]<min_at){
            min_at=at[pi];
            nil[0]=pi;
        }
    }
    cur=0;
    tt=min_at;
    while(cp!=n){
        //printf("\ncurrent: %d\n",nil[cur]);
        as[nil[cur]]=1;
        //printf("%d ",nil[cur]);
        if(rbt[nil[cur]]<=tq){
            tt = tt+rbt[nil[cur]];
            rbt[nil[cur]]=0;
            cs[nil[cur]]=1;
            ct[nil[cur]]=tt;
            
        }
        else{
            tt=tt+tq;
            rbt[nil[cur]] = rbt[nil[cur]]-tq;
        }
        //printf("timeline: %d\n",tt);
        int flag=0;
        int temp;
        for(int pi=0;pi<n;pi++){
            if(as[pi]==0){
                if(tt>=at[pi]){
                    as[pi]=1;
                    flag++;
                    //printf("flag:%d ",flag);
                    if(flag==1){
                        nil[nxt+1]=pi;
                        //printf("\n%d ",pi);
                    }
                    if(flag>1){
                        nil[nxt+flag]=pi;
                        for(int ctr=1;ctr<flag;ctr++){
                            if(at[nil[nxt+ctr+1]]<at[nil[nxt+ctr]]){
                                temp=nil[nxt+ctr+1];
                                nil[nxt+ctr+1]=nil[nxt+ctr];
                                nil[nxt+ctr]=temp;
                            }
                            //printf("%d ",nil[nxt+ctr]);
                        }
                    }
                }
            }
        }
        nxt=nxt+flag;
        //printf("\n%d\n",nxt);
        if(rbt[nil[cur]]!=0){
            nil[nxt+1]=nil[cur];
            nxt++;
        }
        //printf("\nnxt in line:\n");
        //for(int k=cur+1;k<nxt+1;k++){
            //printf("%d ",nil[k]);
        //}
        cur++;
        //printf("\n new current: %d\n",nil[cur]);
        cp=0;
        for(int pi=0;pi<n;pi++){
            cp=cs[pi]+cp;
        }
        //printf("\ntotal processes completed:%d\n",cp);
    }
    int sum_wt=0;
    int sum_tat=0;
    for(int pi=0;pi<n;pi++){
        wt[pi]=ct[pi]-at[pi];
        wt[pi]=wt[pi]-bt[pi];
        tat[pi]=wt[pi]+bt[pi];
        sum_tat=sum_tat+tat[pi];        
        sum_wt=sum_wt+wt[pi];
        //printf("%d ",ct[pi]);
    }
    printf("turn around time\n");
    for(int pi=0;pi<n;pi++){
        printf("%d \n",tat[pi]);
    }
    printf("waiting time\n");
    for(int pi=0;pi<n;pi++){
        printf("%d\n",wt[pi]);
    }
    
    printf("average waiting time: %.2f\n",sum_wt/(float)n);
    printf("average turn around time: %.2f",sum_tat/(float)n);
}