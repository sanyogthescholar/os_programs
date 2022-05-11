#include<stdio.h>
int waitingtime(int proc[],int n,int bursttime[],int waittime[],int arrtime[])
{
	waittime[0]=0;
	int i,starttime[100],completiontime[100];
	starttime[0]=0;
	completiontime[0]=bursttime[0];
	for(i=1;i<n;i++)
	{
		completiontime[i]=bursttime[i]+bursttime[i-1];
	}
	for(i=1;i<n;i++)
	{
		starttime[i]=completiontime[i-1];
		waittime[i]=starttime[i]-arrtime[i];
	}
}

int turnaroundtime(int proc[],int n,int bursttime[],int waittime[],int tat[])
{
	int i;
	for(i=0;i<n;i++)
	{
		tat[i]=bursttime[i]+waittime[i];
	}
}

int avgtime(int proc[],int n,int bursttime[])
{
	int i,waittime[100],tat[100],total_wt=0,total_tat=0;
	int arrtime[]={0,1,3};
	sort(arrtime,proc,bursttime,n);
	waitingtime(proc,n,bursttime,waittime,arrtime);
	turnaroundtime(proc,n,bursttime,waittime,tat);
	printf("Process Number: Burst Time: Wait Time: Turn Around Time: Arrival Time:\n");
	for(i=0;i<n;i++)
	{
		total_wt=total_wt+waittime[i];
		total_tat=total_tat+tat[i];
		printf("p%d\t\t%d\t    %d\t       %d\t\t %d",proc[i],bursttime[i],waittime[i],tat[i],arrtime[i]);
		printf("\n");
	}
	printf("\nAverage waiting time = %f",(float)total_wt/n);
	printf("\nAverage turn around time = %f",(float)total_tat/n);
}

int sort(int x[],int y[],int z[],int n)
{
	int temp;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(x[j]>x[j+1])
			{
				temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
				temp=y[j];
				y[j]=y[j+1];
				y[j+1]=temp;
				temp=z[j];
				z[j]=z[j+1];
				z[j+1]=temp;
			}
		}
	}
}

int main()
{
	int proc[]={1,2,3};
	int n=3;
	int bursttime[]={10,7,3};
	avgtime(proc,n,bursttime);
}
