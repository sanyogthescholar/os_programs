#include<stdio.h>
int part[20],alloc[20],jobs[20],m,n;
void accept()
{
	int i;
	printf("Enter number of partitions:");
	scanf("%d",&m);
	printf("Enter number of jobs:");
	scanf("%d",&n);
	printf("\n");
	for(i=1;i<=m;i++)
	{
		printf("Enter partition=");
		scanf("%d",&part[i]);
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("Enter job size=");
		scanf("%d",&jobs[i]);
	}
}

void allocate()
{
	int i,j,visited[20];
	for(j=1;j<=n;j++)
	{
		visited[j]=0;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(visited[j]!=1&&(part[i]-jobs[j])>0)
			{
				alloc[i]=jobs[j];
				visited[j]=1;
				break;
			}
		}
	}
}

int main()
{
	int i;
	accept();
	allocate();
	printf("\nJobs allocated to partitions are as follows:\n");
	for(i=1;i<=m;i++)
	{
		printf("%d\t",part[i]);
	}
	printf("\n");
	for(i=1;i<=m;i++)
	{
		printf("%d\t",alloc[i]);
	}
	return 0;
}
