#include<stdio.h>
struct testcases
{
	int input1;
	int input2;
	int result;
} test[8] = {
	{ 6 , 6 ,36 },
	{ 5 , 6 ,30 },
	{ 50 , 5 ,30 },
	{ 0 , 0 ,0 },
	{ -1 , 1 , -1 },
	{ -1 , -1 , 1 },
	{ -5 , -6 , -30 },
	{ 12 , -12 , -144 },
};
int addnums(int a, int b)
{
	if (b == 0)
		return a;
	else
		return addnums(a ^ b, (a & b) << 1);
}
int multiplynums(int input1, int input2)
{
	int temp1 = input1, temp2 = input2, count = 0, result = 0;
	if (temp1 == 0 || temp2 == 0) 
		return 0;

	if (temp1 == 1)
		return temp2;

	if (temp2 == 1)
		return temp1;

	if (temp1 < 0)
	{
		temp1 = -1*(temp1);
		count++;
	}
	if (temp2 < 0)
	{
		temp2 = -1*(temp2);
		count++;
	}

	while (temp2 != 0)
	{
		if ((temp2 & 1) == 1)
			result = addnums(result, temp1);
		temp1 <<= 1;
		temp2 >>= 1;
	}
	if(count == 1)
	return -(result);
	else
	return result;
}

void Tests(int n_tests)
{
	int i;
	for (i = 0; i < n_tests; i++)
	{
		int res;
		res = multiplynums(test[i].input1, test[i].input2);
		if (test[i].result == res)
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
