#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct data{
		float x1;
		float x2;
		}data;
float dist(data x,data y)
{
	return sqrt(pow((x.x1-y.x1),2)+pow((x.x2-y.x2),2));
}
data mean(data a[],int n)
{
	data s1;s1.x1=0,s1.x2=0;
	for(int i=0;i<n;i++)
	{
		s1.x1=s1.x1+a[i].x1;
		s1.x2=s1.x2+a[i].x2;
	}
	s1.x1=s1.x1/n;
	s1.x2=s1.x2/n;
	return s1;
}
int main()
{
	int n,i,j=0,k=0;

	printf("enter no. of data\n");
	scanf("%d",&n);

	data d[n],c1,c2,a[n],b[n];

	printf("enter data\n");
	for(i=0;i<n;i++)
		scanf("%f %f",&d[i].x1,&d[i].x2);

	printf("enter centroid 1\n");
	scanf("%f %f",&c1.x1,&c1.x2);
	
	printf("enter centroid 2\n");
	scanf("%f %f",&c2.x1,&c2.x2);

	data m1,m2;

	m1.x1=99999;m1.x1=99999;
	m2.x1=99999;m2.x2=99999;

	while(c1.x1!=m1.x1 && c1.x2!=m1.x2)
	{
		m1=c1;
		m2=c2;
		j=0;k=0;
		for(i=0;i<n;i++)
		{
			if(dist(m1,d[i])<dist(m2,d[i]))
				a[j++]=d[i];
			else
				b[k++]=d[i];
		}
	c1=mean(a,j);
	c2=mean(b,k);
	printf("c1=(%0.2f,%0.2f)   c2=(%0.2f,%0.2f)\n",c1.x1,c1.x2,c2.x1,c2.x2);
	}

	float s1=0,s2=0,of;

	for(i=0;i<j;i++)
		s1=s1+dist(c1,a[i]);

	for(i=0;i<k;i++)
		s2=s2+dist(c2,b[i]);

	printf("cluster 1:");
	for(i=0;i<j;i++)
	{
	printf("(%0.1f,%0.1f) ",a[i].x1,a[i].x2);
	}
	printf("\n");

	printf("cluster 2:");
	for(i=0;i<k;i++)
	{
	printf("(%0.1f,%0.1f)  ",b[i].x1,b[i].x2);
	}
	printf("\n");
	
	of=sqrt(pow(s1,2)+pow(s2,2));
	printf("obj. fn=%0.2f\n",of);
	
	
	
		
	}
	
		

