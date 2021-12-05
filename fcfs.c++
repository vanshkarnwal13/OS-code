#include<iostream>
using namespace std;
 
int main()
{
    int n,i;
    cout<<"Enter total number of processes(maximum 20):";
    cin>>n;
    int at[n],bt[n],sta[n],ct[n],wt[n],tat[n];
    

    cout<<"\nEnter Process arrival Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>at[i];
        
    }

    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }
    
    int j;
    int temp[n];
    for(i=0;i<n;i++){
        temp[i]=at[i];
    }
    
    for (i = 0; i < n-1; i++)
    {
        
        int min_idx = i;
        for (j = i+1; j < n; j++)
        if (temp[j] < temp[min_idx])
            {min_idx = j;
            
            }
        int ss=temp[i];    
        temp[i]=temp[min_idx];
        temp[min_idx]=ss;
    }
    
    int sum=0;
    int idx=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(at[j]==temp[i])
            {
                sum=sum+bt[j];
                ct[idx++]=sum;
                if(temp[i+1]>sum)
                {
                    sum=temp[i+1];

                }
                break;
                
                
            }
            
        }
        
    }
    cout<<endl;
    float avg_tat=0,avg_wt=0;
    cout<<"turn aroune time:"<<endl;
    for(i=0;i<idx;i++)
    {
        tat[i]=ct[i]-at[i];
        avg_tat=avg_tat+tat[i];
        cout<<tat[i]<<endl;
        

    }
    
    cout<<"average turn around time"<<avg_tat/n<<endl;
    cout<<endl;
    cout<<"average waiting time:"<<endl;
    for(i=0;i<idx;i++)
    {
        wt[i]=tat[i]-bt[i];
        avg_wt=avg_wt+wt[i];
        cout<<wt[i]<<endl;
        
    }
    
    cout<<"average waiting time"<<avg_wt/n<<endl;
    return 0;
}