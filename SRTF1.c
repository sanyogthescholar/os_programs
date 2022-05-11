#include<stdio.h>
int main()
{
	int arrtime[20],bt[10],bursttime[20],temp[10],p[10];
	int i,j,temp1,smallest,time,limit,count=0;
	int wt[20],tt[20],m=0,n=0;
	double waittime=0,tat=0,end;
	float avg_wt,avg_tat;
	printf("Enter the total number of processes=");
	scanf("%d",&limit);
	printf("\nEnter Details of %d Processes:",limit);
	for(i=0;i<limit;i++)
	{
		printf("\nEnter Process Number = ");
		scanf("%d",&p[i]);
		printf("\nEnter Arrival Time=");
		scanf("%d",&arrtime[i]);
		printf("\nEnter Burst Time=");
		scanf("%d",&bursttime[i]);
		temp[i]=bursttime[i];
	}
	for(i=0;i<limit;i++)
	{
		bt[i]=bursttime[i];
	}
	bursttime[9]=9999;
	for(time=0;count!=limit;time++)
	{
		smallest=9;
		for(i=0;i<limit;i++)
		{
			if(arrtime[i]<=time&&bursttime[i]<bursttime[smallest]&&bursttime[i]>0)
			{
				smallest=i;
			}
		}
		bursttime[smallest]--;
		if(bursttime[smallest]==0)
		{
			count++;
			end=time+1;
			wt[m++]=waittime=waittime+end-arrtime[smallest]-temp[smallest];
			tt[n++]=tat=tat+end-arrtime[smallest];
		}
	}
	avg_wt=waittime/limit;
	avg_tat=tat/limit;
	for(i=0;i<limit-1;i++)
	{
		for(j=0;j<limit-1;j++)
		{
			if(arrtime[j]>arrtime[j+1])
			{
				temp1=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp1;
				temp1=arrtime[j];
				arrtime[j]=arrtime[j+1];
				arrtime[j+1]=temp1;
				temp1=p[j];
				p[j]=p[j+1];
				p[j+1]=temp1;
			}
		}
	}
	printf("\n---------------------------------\n");
	printf("\nProcess Number:\tBurst Time:\tWait Time:\tTurn Around Time:\tArrival Time:\n");
	for(i=0;i<limit;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i],bt[i],wt[i],tt[i],arrtime[i]);
	}
	printf("\n---------------------------------\n");
	printf("Average Waiting Time = %lf\n",avg_wt);
	printf("Average Turn Around Time = %lf\n",avg_tat);
	return 0;
}
