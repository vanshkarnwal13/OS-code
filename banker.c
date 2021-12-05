#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    //printf("Number of processes:");
    scanf("%d",&n);
    //printf("Number of resources:");
    scanf("%d",&m);
    
    int alloc[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
            }
    }
    int max[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
            }
    }
  
  
    int avail[m];
    for(j=0;j<m;j++){
        scanf("%d",&avail[j]);
    }
    int need[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
  
  
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    
    int y = 0;
    for(int s=0;s<5;s++){
        for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            int flag = 0;
            for (j = 0; j < m; j++) {
                if (need[i][j] > avail[j]){
                    flag = 1;
                    break;
                }
            }
  
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    
    }
    
  
    
    int safe=0;
    for(i=0;i<n;i++){
        if(f[i]==0){
        safe=1;
        break;
        }
    }
    if(safe==0){
        printf("safe sequence\n");
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n; i++)
        printf(" P%d ", ans[i]);
    }
    else{
        printf("not safe sequence");
    }
  
    return (0);
  
    
}