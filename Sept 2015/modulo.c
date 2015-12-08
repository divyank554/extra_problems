#include<stdio.h>
struct testcases
{
	int input1;
	int input2;
	int input3;
	int result;
} test[10] = {
	{ 6 , 5 , 5 , 1 },
	{ 6 , 5 , 5, 2 },
	{ 23 , 50 , 3 , 1 },
	{ 11 , 11 , 6 , 5 },
	{ 550 , 1000 , 7 , 4 },
	{ 0 , 2 , 1 , 0 },
	{ 10 , 0 , 3 , 0},
	{ 10 , 0 , 3 , 1 },
	{ 5 , 5 , 0 , -1 }, // invalid input and excepting invalid output
	{ 5 , 5 , 0 , 0 },
};

int modulo(int input1, int input2 , int input3)
{
	if (input3 == 0)
		return -1;
	if (input2 == 0)
		return 1 % input3;
	int temp = 1;
	input1 = input1 % input3;
	if (input1 == 0)
		return 0;
	for (int i = 0; i < input2; i++)
		temp = (temp*input1) % input3;
	return(temp);
}

void Tests(int n_tests)
{
	for (int i = 0; i < n_tests; i++)
	{
		int res;
		res = modulo(test[i].input1, test[i].input2, test[i].input3);
		if (test[i].result == res)
			printf("Pass\n");
		else
			printf("Fail\n");
	}
}

int main()
{
	int n_tests = 10;
	Tests(n_tests);
	getchar();
}