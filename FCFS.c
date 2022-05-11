#include<stdio.h>
int waitingtime(int proc[],int n,int bursttime[],int waittime[])
{
	waittime[0]=0;
	int i;
	for(i=1;i<n;i++)
	{
		waittime[i]=bursttime[i-1]+waittime[i-1];
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
	waitingtime(proc,n,bursttime,waittime);
	turnaroundtime(proc,n,bursttime,waittime,tat);
	for(i=0;i<n;i++)
	{
		total_wt=total_wt+waittime[i];
		total_tat=total_tat+tat[i];
		printf("Process Number:%d\tBurst Time:%d \t Wait Time:%d \t Turn Around Time:%d ",proc[i],bursttime[i],waittime[i],tat[i]);
		printf("\n");
	}
	printf("\nAverage waiting time = %f",(float)total_wt/n);
	printf("\nAverage turn around time = %f",(float)total_tat/n);
}

int main()
{
	int proc[]={1,2,3};
	int n=3;
	int bursttime[]={10,5,8};
	avgtime(proc,n,bursttime);
}
