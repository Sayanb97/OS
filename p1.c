#include<stdio.h>
#include<conio.h>
int n;
struct Priority
{
	int arrival_t,burst_t,ct,waiting_t,turnaround_t;
	int priority,status;
	char process_name;
}priority_queue[10];
struct Round
{
	int arrival_t,burst_t,ct,waiting_t,turnaround_t;
	int priority,status,TQ ;
	char process_name;
}RR[10];
void main()
{
	int burst=0,time=0,largest;
	char c;
	printf("Enter no. of processes ");
	scanf("%d",n);
	for(int i=0,c='A';i<n;i++,c++)
	{
		priority_queue[i].process_name=c;
		printf("Enter details for Process[%c]",c);
		printf("Enter arrival time ");
		scanf("%d",priority_queue[i].arrival_t);
		printf("Enter burst time ");
		scanf("%d",priority_queue[i].burst_t);
		printf("Enter priority ");
		scanf("%d",priority_queue[i].priority);
		priority_queue.status=0;
	}	
}
