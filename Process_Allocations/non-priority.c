#include<stdio.h>
struct process
{
int id,wt,tat,bt,at;
int available,priority;
}RQ[10],min,TQ[10];

int n=0,time=0;

void getdata()
{
	int i;
	printf("\nEnter the number of process you want to enter:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		TQ[i].id=i+1;
		printf("\nEnter the arrival time for process P%d:",i+1);
		scanf("%d",&TQ[i].at);
		printf("\nEnter the burst time for process P%d:",i+1);
		scanf("%d",&TQ[i].bt);
		printf("\nEnter the priority for process P%d:",i+1);
		scanf("%d",&TQ[i].priority);
	}
}

void check_available()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(TQ[i].available!=-1)
		{
			if(TQ[i].at<=time)
			TQ[i].available=1;
			else
			TQ[i].available=0;
		}
	}
}

void schedule()
{
	int i,count=0;
	check_available();
	while (count<n)
	{
		min.priority=100;
		for(i=0;i<n;i++)
		{
			if((TQ[i].available==1)&&(TQ[i].priority<min.priority))
			min=TQ[i];
		}
		for(i=0;i<n;i++)
		{
			if(TQ[i].id==min.id)
			{
				RQ[count]=TQ[i];
				count++;
				TQ[i].available=-1;
				time+=TQ[i].bt;
				check_available();
			}
		}
	}
}

void waitingtime()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i==0)
		RQ[i].wt=0;
		else
		RQ[i].wt=RQ[i-1].wt+RQ[i-1].bt;
	}
}

void turnaroundtime()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i==0)
		RQ[i].tat=RQ[i].bt;
		else
		RQ[i].tat=RQ[i-1].tat+RQ[i].bt;
	}
}

void display(int n)
{
	int i;
        float awt=0,att=0;
	printf("\nProcess ID \tArrival Time \tBurst Time \tWaiting Time \tTurn Around Time\n ");
	for(i=0;i<n;i++)
	printf("\nP%d \t\t%d \t\t%d \t\t%d \t\t%d",RQ[i].id,RQ[i].at,RQ[i].bt,RQ[i].wt,RQ[i].tat);
 for(i=0;i<n;i++)
	{
        awt+=RQ[i].wt;
	att+=RQ[i].tat;
	}

printf("\n\nAv WT \tAv TT \n%f \t%f",awt/n,att/n);

}

void main()
{
	getdata();
	schedule();
	waitingtime();
	turnaroundtime();
	display(n);
}