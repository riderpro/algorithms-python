#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float mean(float a[],int n)
{
	float s=0;
	for(int i=0;i<n;i++)
	{
		s=s+a[i];
	}
	return s/n;
}
int main()
{
	int n,i,j=0,k=0;
	printf("enter no. of data\n");
	scanf("%d",&n);
	float d[n],c1,c2,a[n],b[n];
	printf("enter data\n");
	for(i=0;i<n;i++)
		scanf("%f",&d[i]);
	printf("enter centroid 1\n");
	scanf("%f",&c1);
	
	printf("enter centroid 2\n");
	scanf("%f",&c2);
	float m1=-1,m2=-1;
	while(c1!=m1)
	{
		m1=c1;
		m2=c2;
		j=0;k=0;
		for(i=0;i<n;i++)
		{
			if(fabs(m1-d[i])<=fabs(m2-d[i]))
				a[j++]=d[i];
			else
				b[k++]=d[i];
		}
	c1=mean(a,j);
	c2=mean(b,k);
	printf("c1=%0.2f,,,c2=%0.2f\n",c1,c2);
	}
	float s1=0,s2=0,of;
	for(i=0;i<j;i++)
		s1=s1+fabs(c1-a[i]);
	for(i=0;i<k;i++)
		s2=s2+fabs(c2-b[i]);
	
	of=sqrt(pow(s1,2)+pow(s2,2));
	printf("obj. fn=%0.2f\n",of);	
		
	}
	
		

