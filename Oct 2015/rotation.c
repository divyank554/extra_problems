#include<stdio.h>
int binarySearch_asc(int *input, int first, int last, int key)
{
	int middle = (first + last) / 2;
	if (key == input[middle])
		return middle;

	else if (key < input[middle])
	return binarySearch_asc(input, middle + 1, last, key);

	else if (key > input[middle])
	return binarySearch_asc(input, first, middle - 1, key);

	return -1;
}

void anticlockwise(int *arr, int d, int n)
{
	int j = 0;
	while (j<d)
	{
		int i, temp;
		temp = arr[0];
		for (i = 0; i < n - 1; i++)
			arr[i] = arr[i + 1];
		arr[i] = temp;
		j++;
	}
}
void clockwise(int *arr, int d, int n)
{
	int j = 0;
	while (j<d)
	{
		int i, temp;
		temp = arr[n - 1];
		for (i = n - 1; i > 0; i--)
			arr[i] = arr[i - 1];
		arr[i] = temp;
		j++;
	}
}


void printArray(int arr[], int size)
{
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", arr[i]);
}
 

int main()
{
   int input[100] = {10,9,8,7,6,5,4,3,2,1};
   int r , length=0;
  // printf("enter the input array of max length 100\n");
   //scanf("%d",&input);
	printf("rotation units\n");
   scanf("%d",&r);
	while(input[length] != '\0')
		length++;
   clockwise(input, r, length);
   
   printArray(input,length);

	int index, temp = 0;
	int final_index;
	int tempvar = input[0];
	do
	{
		index = 1;
		while (input[index + temp] < tempvar && index+temp <= length-1)
			index = (index * 2) + 1;
		printf("index : %d\n", index);
		temp = temp + (index / 2);
			printf("temp : %d\n", temp);
			printf("input[temp] : %d\n",input[temp]);
			printf("input[temp+1] : %d\n",input[temp+1]);
				printf("input[temp-1] : %d\n",input[temp-1]);
		if (input[temp] < input[temp + 1] && input[temp] < input[temp - 1])
		{
			printf("ans;vhdfu;a\n");
			final_index = temp;
			break;
		}
		else
			tempvar = input[temp];

	} while (input[temp] > input[temp + 1] && input[temp] < input[temp - 1]);
	
	printf("resut : %d\n",final_index);
	 int key,result;
	 printf("enter the key : ");
	 scanf("%d",&key);
	if (key > input[0])
		result =  binarySearch_asc(input, final_index + 1, length-1, key);
	else if (key < input[0])
		result = binarySearch_asc(input, 1 , final_index , key);
	else
		result = 0;

	printf("result : %d\n",result);
   getchar();
   return 0;
}
