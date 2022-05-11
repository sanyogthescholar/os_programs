#include<stdio.h>
int main()
{
	int bursttime[20],proc[20],waittime[20],tat[20],i,j,n,pos,temp,min,total=0;
	float avg_wt,avg_tat;
	printf("Enter the number of processes=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Process and its Burst Time=");
		scanf("%d%d",&proc[i],&bursttime[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=bursttime[i];
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(min>bursttime[j])
			{
				min=bursttime[j];
				pos=j;
			}
		}
		bursttime[pos]=bursttime[i];
		bursttime[i]=min;
		temp=proc[i];
		proc[i]=proc[pos];
		proc[pos]=temp;
	}
	waittime[0]=0;
	for(i=1;i<n;i++)
	{
		waittime[i]=0;
		for(j=0;j<i;j++)
			waittime[i]=waittime[i]+bursttime[j];
		total=total+waittime[i];
	}
	avg_wt=(float)total/n;
	//printf("\nAverage Waiting Time=%d",avg_wt);
	total=0;
	for(i=0;i<n;i++)
	{
		tat[i]=waittime[i]+bursttime[i];
		total=total+tat[i];
	}
	avg_tat=(float)total/n;
	printf("\n");
	printf("---------------------------------------------------------");
	printf("\n");
	//printf("\nAverage Turn Around Time=%d",avg_tat);
	printf("Process Number: Burst Time: Wait Time: Turn Around Time:\n");
	for(i=0;i<n;i++)
	{
		printf("p%d              %d           %d          %d",proc[i],bursttime[i],waittime[i],tat[i]);
		printf("\n");
	}
	printf("\nAverage Waiting Time = %f",avg_wt);
	printf("\nAverage Turn Around Time = %f",avg_tat);
}
