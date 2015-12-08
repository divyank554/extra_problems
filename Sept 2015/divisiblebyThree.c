#include<stdio.h>
struct testcases
{
	char input[10000];
	int count;
	int remainder;
} test[7] = {
	{ { "183425366689587475893" }, 200000,  0 },
	{ { "183425366689587475893" }, 200000,  -1 },
	{ { "183425366689587416431758931" }, 2,  0 },
	{ "123",  300, 0 },
	{ "123", 301, 0 },
	{ "72" , 1000, 0 },
	{ "16412", 18 ,0 },
};
int div3(char *input, int count)
{
	int i, sum = 0, temp , res=0;

	for (i = 0; i < input[i] != '\0'; i++)
		sum = sum + input[i]-'0';
		
	printf("\nsum : %d", sum);
	while (sum != 0)
	{
		temp = sum % 10;
		res = res + temp;
		sum = sum / 10;
		if (sum == 0)
			if(res>10)
			sum = res;
	}
	printf("\nsum after : %d \n", res);
	if (res % 3 == 0)
		{
			if (count > 0)
				return 0;
			else
				return -1;
		}
		else
		{
			if (count % 3 == 0)
				return 0;
			else
				return -1;
		}
}

void Tests(int n_tests)
{
	int i;
	for (i = 0; i < n_tests; i++)
	{
		int res = -1;
		res = div3(test[i].input,test[i].count);
		if (res == test[i].remainder)
			printf("Pass\n");
		else
			printf("Fail\n");
	}
}
int main()
{
	int n_tests = 7;
	Tests(n_tests);
	getchar();
}
