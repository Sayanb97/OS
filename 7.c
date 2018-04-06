#include<stdio.h>
struct process
{
    char process_name;
    int arrival_t,burst_t,ct,waiting_t,tt,pri,burst_t1;
}process[10],process1[10];
void main()
{
	struct process temp;
    int i,time=0,tq1,tq2,largest,limit,count=0;
	int k,pf2=0,limit2,n,pos,j,flag=0;
    float average_waiting_time,average_turnaround_time;
    float wait_time=0,turnaround_time= 0;
    printf("\nEnter Total Number of Processes:   ");
    scanf("%d",&limit);
    n=limit;
    for(i=0;i<limit;i++)
    {
    	printf("\nEnter Process name: ");
    	fflush(stdin);
        scanf("%c",&process[i].process_name);
        printf("\nEnter Details For processor %c:\n",process[i].process_name);
        printf("Enter Arrival Time: ");
        scanf("%d",&process[i].arrival_t);
        printf("Enter Burst Time: ");
        scanf("%d",&process[i].burst_t);
        process[i].burst_t1=process[i].burst_t;
        printf("Enter Priority:\t");
        scanf("%d",&process[i].pri);
    }
    printf("\nEnter Time Quantum for Fixed Priority Queue: ");
    scanf("%d",&tq1);
    printf("\nEnter Time Quantum for Round Robin Queue: ");
    scanf("%d",&tq2);
    printf("\n\nProcess\t  |  Turnaround Time  |  Waiting Time\n\n");
    for(i=0;i<limit;i++)
    {
        pos=i;
        for(j=i+1;j<limit;j++)
        {
            if(process[j].arrival_t<process[pos].arrival_t)
                pos=j;
        }
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
    
    time=process[0].arrival_t;
    for(i=0;limit!=0;i++)
    {
    	while(count!=tq1)
    	{
    		count++;
    		if(process[i].arrival_t<=time)
    		{
    			for(j=i+1;j<limit;j++)
    			{
    				if(process[j].arrival_t==time&&process[j].pri<process[i].pri)
    				{
    					process1[pf2]=process[i];
						pf2++;
    					for(k=i;k<limit-1;k++)
    						process[k]=process[k+1];
    					limit--;
						count=0;
    					i=j-1;
    					j--;
					}
				}
			}
			
			time++;
			process[i].burst_t--;
			if(process[i].burst_t==0)
			{
				process[i].tt=time-process[i].arrival_t;
				process[i].waiting_t=process[i].tt-process[i].burst_t1;
				printf("%c\t  |  \t%d\t  |  \t%d\n",process[i].process_name,process[i].tt,process[i].waiting_t);
				turnaround_time+=time-process[i].arrival_t;
				wait_time+=turnaround_time-process[i].burst_t1; 
    			
    			for(k=i;k<limit-1;k++)
    				process[k]=process[k+1];i--;
    			limit--;
				count=tq1;break;
			}
		}
		count=0;
		if(process[i].burst_t!=0)
		{
			process1[pf2]=process[i];
			pf2++;
			for(k=i;k<limit-1;k++)
    			process[k]=process[k+1];
    		limit--;
		}
			if(i==limit-1)
				i=-1;
	}
	
	limit2=pf2;
	for(count=0;limit2!=0;) 
	{ 
		if(process1[count].burst_t<=tq2&&process1[count].burst_t>0) 
    	{ 
    		time+=process1[count].burst_t; 
    		process1[count].burst_t=0; 
    		flag=1; 
    	} 
    	else if(process1[count].burst_t>tq2) 
    	{ 
    		process1[count].burst_t-=tq2; 
    		time+=tq2; 
    	} 
    	if(process1[count].burst_t==0&&flag==1) 
    	{ 
    		limit2--; 
    		process1[count].tt=time-process1[count].arrival_t;
			process1[count].waiting_t=process1[count].tt-process1[count].burst_t1; 
			printf("%c\t  |  \t%d\t  |  \t%d\n",process1[count].process_name,process1[count].tt,process1[count].waiting_t); 
    		turnaround_time+=time-process1[count].arrival_t; 
    		wait_time+=time-process1[count].arrival_t-process1[count].burst_t1;
    		for(k=count;k<limit2;k++)
    			process1[k]=process1[k+1];count--;
    		flag=0; 
    	} 

    	if(count==limit2-1) 
      		count=0; 
    	else 
    		count++; 
    }
    printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
    printf("\nAverage Turnaround Time = %f",turnaround_time*1.0/n);   
}
