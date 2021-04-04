//round robin scheduling 
#include<stdio.h>
#include<conio.h>
void main() 
{
    int n,i,bt[10],rem_bt[10],qt,temp,count=0,sq=0,wt[10],tat[10];
    float awt=0,atat=0;
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    	printf("Enter burst time of process %d:",i);
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("Enter quantum time:");
    scanf("%d",&qt);
    while(1)
    {
        for(i=0;i<n;i++)
        {
            temp=qt;
            if(rem_bt[i]==0)
            {
                count++;
                continue;
            }
            if(rem_bt[i]>qt)
            	rem_bt[i]=rem_bt[i]-qt;
            else
            if(rem_bt[i]>=0)
            {
                temp=rem_bt[i];
                rem_bt[i]=0;
            }
            sq=sq+temp;
            tat[i]=sq;
        }
    	if(n==count)
    		break;
    }
	printf("\n Process\t Brust Time\t Turn around Time\t Waiting time\n");
	for(i=0;i<n;i++)
	{
    	wt[i]=tat[i]-bt[i];
    	awt=awt+wt[i];
    	atat=atat+tat[i];
    	printf("\n %d\t %d\t %d\t %d\t\n",i+1,bt[i],tat[i],wt[i]);
	}
	awt=awt/n;
	atat=atat/n;
	printf("\nAverage Waiting Time=%f\n",awt);
	printf("\nAverage Turnaround Time=%f\n",atat);
getch();
}
