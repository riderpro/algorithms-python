#include <stdio.h>

int main(void) {
	// your code goes here
	int x[]={999,-3,2,-1,-2,1,5,-3};
	int i=0;
	
	int n=8;
	int max_so_far=x[0];
	int curr_max=x[0];
	for(i=1;i<n;i++)
	{
		curr_max=(x[i]>curr_max+x[i])?x[i]:(curr_max+x[i]);
		max_so_far=(curr_max>max_so_far)?curr_max:max_so_far;
	}
	printf("%d\n",max_so_far);
	return 0;
}