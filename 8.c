#include<stdio.h>
int total_time=120;//mins
int nf;
int ns;
struct Faculty
{
    char* faculty_name;
    int ftime;
}f[10];
struct Student
{
	char* student_name;
	int stime;
}s[10];
void main()
{   
    int i,f_t_slice,s_t_slice;
	printf("Enter no. of faculty ");
	scanf("%d",&nf);
	for(i=0;i<nf;i++)
	{
		printf("Enter name of faculty%d ",(i+1));
		scanf("%s",&f[i].faculty_name);
		printf("Enter time(in mins) of query for faculty%d ",(i+1));
		scanf("%d",&f[i].ftime);
	}
	printf("Enter no. of students ");
	scanf("%d",&ns);
	for(i=0;i<ns;i++)
	{
		printf("Enter name of student%d ",(i+1));
		scanf("%s",&s[i].student_name);
		printf("Enter time(in mins) of query for student%d ",(i+1));
		scanf("%d",&s[i].ftime);
	}
	f_t_slice=60/nf;
	s_t_slice=60/ns;
	for(i=0;i<nf;i++)
	{
		
	}
}
