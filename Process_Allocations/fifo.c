#include<stdio.h>
/* Making structure for the process including process-id, burst-time,turn-around-time,waiting-time.*/
struct process	
{
	int pid;
	int bt,tat,wt;
    float avg;
}RQ[10];
//Global constant:
int front=0,rear=0;
//Adding various processes(addprocesses,waiting-time,turnaroundtime,display):
void addprocesses(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		RQ[i].pid=i+1;
		printf("\nEnter the burst time for P%d:",RQ[i].pid);
		scanf("%d",&RQ[i].bt);
		rear++;
		if(i>=10)
		{
			printf("\nQueue Full!");
			return;
		}
	}
}

void waitingtime()
{
	int i;
	for(i=front;i<rear;i++)
	{
		if(i==0)
		RQ[i].wt=0;
		else
		{
			RQ[i].wt=RQ[i-1].wt+RQ[i-1].bt;
		}
	}
}

void turnaroundtime()
{
	int i;
	for(i=front;i<rear;i++)
	{
		if(i==0)
		RQ[i].tat=RQ[i].bt;
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
	printf("\nProcess ID \tBurst Time \tWaiting time \tTurnaround Time\tAv WT");
	for(i=front;i<rear;i++)
	{
		printf("\nP%d \t\t%d \t\t%d \t\t%d",RQ[i].pid,RQ[i].bt,RQ[i].wt,RQ[i].tat);
	}
        for(i=front;i<rear;i++)
	{
        awt+=RQ[i].wt;
	att+=RQ[i].tat;
	}
printf("\n");
printf("\t\t%f \n\nAv TT \n%f",awt/n,att/n);

}

//Adding functions to main:
void main()
{
	int n;
	printf("\nEnter the number of processes you want to enter (max=10):");
	scanf("%d",&n);
	addprocesses(n);
	waitingtime();
	turnaroundtime();
	display(n);
}