#include<stdio.h>
#include<stdlib.h>
struct process
{
    int pid;
    int bt,wt,tat;
}RQ[10],p,temp;

int rear=0,front=0,count=0;

void addprocesses(int n)
{
    int i;
	for(i=0;i<n;i++)
	{
		if(rear==10)
		{
		printf("\nQueue Full\n");
		return;
		}
		else
		{
		printf("\nInput data for Process:P%d\n",i+1);
		p.pid=i+1;
		printf("\nEnter Burst Time for the process:");
		scanf("%d",&p.bt);
		RQ[rear]=p;
		rear++;
		count++;
		}
	}

}

void schedule()
{
	int i,j;
	if((rear==0)||(rear==1))
	return;
	else
	{
		for(i=rear-1;i>front;i--)
		{
			for(j=i-1;j>=front;j--)
			{
				if(RQ[j].bt>RQ[i].bt)
				{
					temp=RQ[i];
					RQ[i]=RQ[j];
					RQ[j]=temp;
				}
			}
		}
	}
}

void waitingtime()
{
    int i;
    for(i=front;i<=rear;i++)
	{
		if(i==front)
			{
				RQ[i].wt=0;
			}
		else
			{
				RQ[i].wt=RQ[i-1].wt+RQ[i-1].bt;
			}
	}
}

void turnaroundtime()
{   int i=0;
    for(i=front;i<=rear;i++)
	{
			if(i==front)
			{
				RQ[i].tat=RQ[i].bt;
			}
			else
			{
				RQ[i].tat=RQ[i-1].tat+RQ[i].bt;
			}

	}
}

void display(int n)
{
    int i;
    float awt=0,att=0;
    printf("\nProcess ID \tBurst Time \tWaiting Time \tTurn Around Time \tAv WT");
    for(i=front;i<rear;i++)
    {
		if(RQ[i].pid==0)
		continue;
		else
		printf("\nP%d\t\t%d\t\t%d\t\t%d",RQ[i].pid,RQ[i].bt,RQ[i].wt,RQ[i].tat);
    }
        for(i=front;i<rear;i++)
	{
        awt+=RQ[i].wt;
	att+=RQ[i].tat;
	}
printf("\t\t%f \n\nAv TT \n%f",awt/n,att/n);
}

void main()
{
	int n;
	printf("\nHow many processes would you like to enter (max=10) :");
	scanf("%d",&n);
	addprocesses(n);
	schedule();
	waitingtime();
	turnaroundtime();
	display(n);
}