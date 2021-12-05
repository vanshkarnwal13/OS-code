#include<stdio.h>

struct frame
{
    int pno;
    int counter;
}frames[5];

int ref_str[]={1,2,6,5,3,2,5,6,1,3};
int np = 15, n, i, j, currtime;

int page_found (int pno)
{
    int i;
    for(i=0; i<n; i++)
    if(frames[i].pno==pno)
    return i;
    return -1;
}

int get_lru()
{
    int min=0;
    for(i=0;i<n;i++)
    if(frames[i].counter<frames[min].counter)
    min=i;
    return min;
}

int main()
{
    int i,j,pno,p,page_fault=0,flag;
    printf("\n enter how many frames:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        frames[i].pno=-1;
        frames[i].counter=-1;
    }
    printf("\n page no \t frames \t\t page fault");
    currtime=1;
    for(p=0;p<np;p++)
    {
        flag=0;
        pno=ref_str[p];
        j=page_found(pno);
        if(j==-1)
        {
            page_fault++;
            j=get_lru();
            frames[j].pno=pno;
            flag=1;

        }
        frames[j].counter=currtime;
        currtime++;
        printf("\n%5d\t",pno);
        for(i=0;i<n;i++)
        printf("%2d:%2d",frames[i].pno, frames[i].counter);
        if(flag==1)
        printf("\t YES");
        else
        printf("\t NO");

    }
    printf("\n no of page fault: %d",page_fault);
}