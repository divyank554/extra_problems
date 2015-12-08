#include<stdio.h>
struct testcases
{
	int input;
	int result;
} test[9] = {
	{ 123 , 0 },
	{ 312 , 4},
	{ 21 , 1 },
	{ 210 , 5 },
	{ 5421 , 23 },
	{ 8654 , 23 },
	{ 54321 , 119 },
	{ 54321 , 120 },
	{ 987654321 , 362879 },
};
void Sort2(int *input, int len_input)
{
	int swap;
	int i, j;
	for (i = 0; i < len_input; i++)
	{
		for (j = 0; j < len_input - i - 1; j++)
		{
			if (input[j] > input[j + 1])
			{
				swap = input[j];
				input[j] = input[j + 1];
				input[j + 1] = swap;
			}
		}
	}
}

int search(int *input, int count, int ele)
{
	int i;
	for (i = 0; i < count; i++)
	{
		if (ele == input[i])
		{
			return i;
			break;
		}
	}
	return -1;
}

int factofnum(int num)
{
	int i, fact = 1;
	for (i = 1; i <= num; i++)
	{
		fact = fact * i;
	}
	return fact;
}
int minrank(int input)
{
	int temp = input;
	int b[100];
	int c[100];
	int i = 0, count1 = 0, temp2, result = 0;

	while (temp != 0)
	{
		b[i] = temp % 10;
		temp = temp / 10;
		i++;
		count1++;
	}
	for (i = 0; i<count1; i++)
		c[i] = b[i];
	Sort2(b, count1);
	int x;
	while (count1>0)
	{
		temp2 = c[count1 - 1];
		int res = search(b, count1, temp2);
		result = result + (res * factofnum(count1 - 1));
		for (x = res; x < count1 - 1; x++)
			b[x] = b[x + 1];
		count1--;
	}

	return result;
}
void Tests(int n_tests)
{
	int i;
	for (i = 0; i < n_tests; i++)
	{
		int res;
		res = minrank(test[i].input);
		if (test[i].result == res)
			printf("Pass\n");
		else
			printf("Fail\n");
	}
}
int main()
{
	int n_tests = 9;
	Tests(n_tests);
	getchar();
}
