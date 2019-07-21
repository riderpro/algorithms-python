#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int c=2,k=3;
float g=1.25;
typedef struct data{
		float x;
		float y;
		float z;
		}data;
float dist(data a,data b)
{
	return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2)+pow((a.z-b.z),2));
}
int main()
{
	int n,i,j,p,q;
	
	printf("enter no. data points\n");
	scanf("%d",&n);

	data d[n],cc[c],s2;
	float m[n][c],m1[n][c],s1=0;
	
	printf("enter data points\n");
	for(i=0;i<n;i++)
	{
		printf("data no. %d:",i+1);
		scanf("%f %f %f",&d[i].x,&d[i].y,&d[i].z);
	}
	printf("hi");
	for(i=0;i<n;i++){
		for(j=0;j<c;j++){
			m[i][j]=(float)(rand()%10000)/10000;
		}
	}	

	while(1)
	{
	for(i=0;i<n;i++)
	{+
		for(j=0;j<c;j++)
		{m1[i][j]=m[i][j];}
	}

	for(i=0;i<c;i++)
	{
		s1=0;s2.x=0;s2.y=0;s2.z=0;
		for(j=0;j<n;j++)
		{
			s1=s1+pow(m[j][i],g);
			s2.x=s2.x+(pow(m1[j][i],g)*d[j].x);
			s2.y=s2.y+(pow(m1[j][i],g)*d[j].y);
			s2.z=s2.z+(pow(m1[j][i],g)*d[j].z);
		}
		cc[i].x=s2.x/s1;
		cc[i].y=s2.y/s1;
		cc[i].z=s2.z/s1;
	}
	for(i=0;i<c;i++)
	{
		for(j=0;j<n;j++)
		{
			if(dist(cc[i],d[j])==0)
				m[j][i]=0;
			else
			{
				s1=0;
				for(int x=0;x<c;x++)
				{
				s1=s1+(pow((dist(cc[i],d[j])/dist(cc[x],d[j])),2/(g-1)));
				}
			m[j][i]=1/s1;
			}
		}						


	}
	int f=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<c;j++)
		{
			if(fabs(m[i][j]-m1[i][j])!=0.0001)
			{
			f=1;
			break;	
			}
		}
		if(f==1)
		break;
	}
	if(f==0)
	break;
	}
	for(i=0;i<c;i++)
	{
		printf("(%0.5f,%0.5f,%0.5f)\n",cc[i].x,cc[i].y,cc[i].z);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%0.5f    ",m[i][j]);
		}
		printf("\n");
	}	
			
}
