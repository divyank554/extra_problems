#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void main()
{
	int *input;
	printf("\nenter the input array\n");
	int i=1, temp1;
	input = (int*)malloc(sizeof(int));

	do {
		scanf("%d", &temp1);
		if (i == -1) 
			break;
		input[i - 1] = temp1;
		realloc(input, ++i);
	} while (1);

	int index, temp = 0;
	int final_index;
	do
	{
		index = 1;
		while (input[index + temp] != 0)
			index = (index * 2);

		temp = temp + (index / 2);

		if (input[temp] < input[temp - 1] && input[temp + 1] == 0)
			final_index = temp - 1;
		else if (input[temp] > input[temp + 1] && input[temp] > input[temp - 1])
			final_index = temp;
		else if (input[temp + 3] == 0)
			final_index = temp + 1;

	} while (input[temp] < input[temp + 1] && input[temp] > input[temp - 1]);

	printf("\nlength of the array = %d\n", final_index);
	getch();
}