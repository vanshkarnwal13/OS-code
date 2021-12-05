#include<stdio.h>
void main()
{
    int frame[10];
    int i, j, k, p, nframe, page[50];
    int flag=0, pfault=0, pos=0;
    printf("enter the number of frames:");
    scanf("%d", &nframe);
    for(i=0; i<nframe; i++)
    frame[i]=-1;
    printf("enter the number of page:\n");
    scanf("%d",&p);
    printf("enter the pages:");
    for(i=0;i<p;i++)
    {
        scanf("%d",&page[i]);
    }
    for(i=0;i<p;i++)
    {
        flag=0;
        for(j=0;j<nframe;j++)
        {
            if(frame[j]==page[i])
            {
                printf("\n HIT");
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            frame[pos]=page[i];
            pos++;
            printf("\n FAULT");
            pfault++;
            if(pos>=nframe)
            pos=0;
        }
        for(k=0;k<nframe;k++)
        printf("%d\t",frame[k]);
    }
    printf("\n number of page fault is: %d", pfault);
}