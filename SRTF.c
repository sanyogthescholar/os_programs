#include<stdio.h>
int main()
{
	int arrtime[20],bursttime[20],temp[10];
	int i,smallest,time,limit,count=0;
	double waittime=0,tat=0,end;
	float avg_wt,avg_tat;
	printf("Enter the total number of processes=");
	scanf("%d",&limit);
	printf("\nEnter Details of %d Processes:",limit);
	for(i=0;i<limit;i++)
	{
		printf("\nEnter Arrival Time=");
		scanf("%d",&arrtime[i]);
		printf("\nEnter Burst Time=");
		scanf("%d",&bursttime[i]);
		temp[i]=bursttime[i];
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
			waittime=waittime+end-arrtime[smallest]-temp[smallest];
			tat=tat+end-arrtime[smallest];
		}
	}
	avg_wt=waittime/limit;
	avg_tat=tat/limit;
	printf("\n");
	printf("------------------------");
	printf("\n");
	printf("Average Waiting Time = %lf\n",avg_wt);
	printf("Average Turn Around Time = %lf\n",avg_tat);
	return 0;
}
