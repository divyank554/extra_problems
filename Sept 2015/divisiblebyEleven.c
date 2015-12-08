#include<stdio.h>
#include<math.h>
struct testcases
{
	char input[10000];
	int remainder;
} test[7] = {
	{ { "11111234567892511234" }, 0 },
	{ "918082", 0 },
	{ "99999449",   0 },
	{ "1234567898765432", 0 },
	{ "91229122912291229122912291229122912291229122" , 0 },
	{ "402481720894", 0 },
};
int div(char *input)
{
	int i;
	int sum_even = input[0] - '0', sum_odd = input[1] - '0';
	int input_len = 0;

	for (i = 2; i<input[i]!='\0'; i++)
	{
		if(i%2==0)
		sum_even = sum_even + (input[i] - '0');
		else
		sum_odd = sum_odd + (input[i] - '0');
	}

	sum_even = sum_11(sum_even);
	sum_odd = sum_11(sum_odd);

	if (sum_even - sum_odd == 0 || (sum_even-sum_odd)%11 == 0)
		return 0;
	else
		return -1;
}
int sum_11(int sum)
{
	int input = sum;
	int temp_sum;
	do {
		int sum1 = 0, sum2 = 0;
		while (input > 0)
		{
			int inter = input;
			input = input / 10;
			sum1 = sum1 + (inter - input * 10);
			inter = input;
			input = input / 10;
			sum2 = sum2 + (inter - input * 10);
		}
		temp_sum = sum1 - sum2;
	} while (temp_sum > 10);

	return temp_sum;
}
void Tests(int n_tests)
{
	int i;
	for (i = 0; i < n_tests; i++)
	{
		int res;
		res = div(test[i].input);
		if (res == test[i].remainder)
			printf("Pass\n");
		else
			printf("Fail\n");
	}
}
int main()
{
	int n_tests = 6;
	Tests(n_tests);
	getchar();
}
