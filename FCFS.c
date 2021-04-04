//FCFS
#include<stdio.h>
int main()
{
	int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
	int n,i,j,k,sum=0;
	float TotalTAT=0,TotalWT=0;
	printf("Enter no. of Processess:\n");
	scanf("%d",&n);
	printf("Enter arrival time and brust time for each process:\n");
	for(i=0;i<n;i++)
	{
		printf("arrival time of process[%d]:",i+1);
		scanf("%d",&at[i]);
		printf("brust time of process[%d]:",i+1);
		scanf("%d",&bt[i]);
	}
	for(j=0;j<n;j++)
	{
		sum+=bt[j];
		ct[j]+=sum;
	}
	for(k=0;k<n;k++)
	{
		tat[k]=ct[k]-at[k];
		TotalTAT+=tat[k];
	}
	for(k=0;k<n;k++)
	{
		wt[k]=tat[k]-bt[k];
		TotalWT+=wt[k];
	}
	printf("Solution:");
	printf("P#\t AT\t BT\t CT\t TAT\t WT\t \n\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t %d\t %d\t %d\t %d\t %d\t \n",i+1, at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("\n\n Average Turn Around Time= %f\n",TotalTAT/n);
	printf("Average waiting Time= %f\n",TotalWT/n);
return 0;	
}
