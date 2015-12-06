#include<stdio.h>

int largestSum(int array[], int size)
{
   int max = 0, max_end = 0,i;
   for (i = 0; i < size; i++)
   {
       max_end = max_end + array[i];
       if (max_end < 0)
           max_end = 0;
       else if (max < max_end)
           max = max_end;
   }
   return max;
}

int main()
{
	int array[50];
	int len,i,sum;
	
	printf("Enter Length: \n");
	scanf(" %d",&len);
	
	printf("Enter Elements: \n");
	for(i = 0; i<len; i++)
		if(scanf(" %d",&array[i]) != 1)
           return;
	sum = largestSum(array,len);
	printf("largest cont. sum in the array : %d\n",sum);

	getchar();
}
