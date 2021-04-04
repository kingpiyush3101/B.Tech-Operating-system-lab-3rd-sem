//SJF
#include<stdio.h>
#include<conio.h>
struct ff
{
	int pid,ser,wait;
}p[20];
struct ff tmp;
main()
{
	int i,n,j,tot=0,avwait,totwait=0,tturn=0,aturn;
	printf("Enter the no. of process:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter process id:");
		scanf("%d",&p[i]);
		printf("Enter service time:");
		scanf("%d",&p[i].ser);
		p[i].wait=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].ser>p[j].ser)
			{
				tmp=p[i];
				p[i]=p[j];
				p[j]=tmp;
			}
		}
	}	
	printf("PID\t SER\t WAIT\t TAT\n");
	for(i=0;i<n;i++)
	{
		tot=tot+p[i].ser;
		tturn=tturn+tot;
		p[i+1].wait=tot;
		totwait=totwait+p[i].wait;
		printf("%d\t %d\t %d\t %d\n",p[i].pid,p[i].ser,p[i].wait,tot);
	}
	avwait=totwait/n;
	aturn=tturn/n;
	printf("Total Waiting Time=%d\n",totwait);
	printf("Average Waiting Time=%d\n",avwait);
	printf("Total Turnaround Time=%d\n",tturn);
	printf("Average Trunaround Time=%d\n",aturn);
getch();
}	
