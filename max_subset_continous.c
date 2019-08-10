#include <stdio.h>

int main(void) {
	// your code goes here
	//int x[]={999,-3,2,-1,-2,1,5,-3};
	int n;
	printf("\nEnter n:\n");
	scanf("%d",&n);
	int *x=(int *)malloc(sizeof(int)*n);
	int i=0;
	printf("Enter %d nos:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	
	int max_so_far=x[0];
	int curr_max=x[0];
	for(i=1;i<n;i++)
	{
		curr_max=(x[i]>curr_max+x[i])?x[i]:(curr_max+x[i]);
		max_so_far=(curr_max>max_so_far)?curr_max:max_so_far;
	}
	printf("\nMax continuous sum:%d\n",max_so_far);
	return 0;
}
