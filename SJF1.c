#include<stdio.h>
int main()
{
	int bursttime[20],proc[20],waittime[20],tat[20],arrtime[20],i,j,n,pos,temp,min,total=0;
	float avg_wt,avg_tat;
	printf("Enter the number of processes=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Process and its Burst Time=");
		scanf("%d%d",&proc[i],&bursttime[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("Enter arrival time of each process=");
		scanf("%d",&arrtime[i]);
	}
	for(i=0;i<n-1;i++) //Sorting proc and arrtime as per arrtime
	{
		for(j=0;j<n-1;j++)
		{
			if(arrtime[j]>arrtime[j+1])
			{
				temp=arrtime[j];
				arrtime[j]=arrtime[j+1];
				arrtime[j+1]=temp;
				temp=proc[j];
				proc[j]=proc[j+1];
				proc[j+1]=temp;
			}
		}
	}
	int starttime[20],completiontime[20];
	starttime[0]=0;
	completiontime[0]=bursttime[0];
	
	for(i=1;i<n;i++)
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
		temp=arrtime[i];
		arrtime[i]=arrtime[pos];
		arrtime[pos]=temp;
	}
	
	for(i=1;i<n;i++)
	{
		starttime[i]=completiontime[i-1];
		completiontime[i]=bursttime[i]+starttime[i];
	}
	waittime[0]=0;
	for(i=1;i<n;i++)
	{
		waittime[i]=starttime[i]-arrtime[i];
		total=total+waittime[i];
	}
	avg_wt=(float)total/n;
	total=0;
	tat[0]=waittime[0]+bursttime[0];
	for(i=1;i<n;i++)
	{
		tat[i]=waittime[i]+bursttime[i];
		total=total+tat[i];
	}
	total=total+tat[0];
	avg_tat=(float)total/n;
	printf("\n");
	printf("---------------------------------------------------------------------");
	printf("\n");
	printf("Process Number: Burst Time: Wait Time: Turn Around Time: Arrival Time:\n");
	for(i=0;i<n;i++)
	{
		printf("p%d\t\t%d\t    %d\t       %d\t\t %d",proc[i],bursttime[i],waittime[i],tat[i],arrtime[i]);
		printf("\n");
	}
	printf("\nAverage Waiting Time = %f",avg_wt);
	printf("\nAverage Turn Around Time = %f",avg_tat);
}
