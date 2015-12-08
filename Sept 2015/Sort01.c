#include<stdio.h>
#include<math.h>

void Sort3(int *input, int len_input)
{
	int swap;
	int i, j;
	for (i = 0,j=len_input-1 ; i < len_input ; i++,j--)
	{
			if (input[i]==0 && input[j]==1)
			{
				swap = input[j];
				input[j] = input[i];
				input[i] = swap;
			}
		}
	printf("output3 :\n");

	for (i = 0; i < len_input; i++)
		printf(" %d", input[i]);
	printf("\n");
}
void Sort2(int *input, int len_input)
{
	int swap;
	int i, j;
	for (i = 0; i < len_input; i++)
	{
		for (j = 0; j < len_input- i-1; j++)
		{
			if (input[j] > input[j + 1]) 
			{
				swap = input[j];
				input[j] = input[j + 1];
				input[j + 1] = swap;
			}
		}
	}
	printf("output2 :\n");

	for (i = 0; i < len_input; i++)
		printf(" %d", input[i]);
	printf("\n");
}
void Sort1(int *input, int len_input)
{
	int i;
	int count1 = 0;
	int j = len_input;
	for ( i = 0; i < len_input; i++)
	{
		if (input[i] == 1)
			count1++;
	
		if(input[i]!= 0 && input[i]!= 1 )
		{
			input[0] = -1;
			return;
		}
	}
	for ( i = 0; i < len_input - count1; i++)
		input[i] = 0;
	for ( i = len_input-1; i >=count1; i--)
		input[i] = 1;
	printf("output 1 :\n");

	for (i = 0; i < len_input; i++)
		printf(" %d", input[i]);
	printf("\n");
}
int main()
{
	int input[100];
	printf("enter the length of array\n");
	int len;
	int i;
	scanf("%d",&len);
	printf("enter the number(0 or 1)")
	for(i=0;i<len;i++)
		scanf("%d",&input[i]);
	Sort1(input,len);
	Sort2(input,len);
	Sort3(input,len);
}
