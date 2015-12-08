#include<stdio.h>
struct testcases
{
	char input[10000];
	int count;
	int remainder;
} test[7] = {
	{ { "9618378373" },  11,  0},
	{ "123",  300, 0 },
	{ "123",  301, 0 },
	{ "1627" , 132, 0 },
	{ "16412" , 20,0 },
	{ { "123456789" },  4,  0},
};

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

int div(char *input, int input_len)
{
	int i;
	int sum_even = input[0] - '0', sum_odd = input[1] - '0';
	
		for (i = 2; i<input[i]!='\0'; i++)
	{
		if(i%2==0)
		sum_even = sum_even + (input[i] - '0');
		else
		sum_odd = sum_odd + (input[i] - '0');
	}
	sum_even = sum_11(sum_even);
	sum_odd = sum_11(sum_odd);

		if (sum_even - sum_odd == 0 || (sum_even-sum_odd) % 11 == 0)
		return 0;
	else
		return -1;
}

int div11(char *input, int count)
{
	int input_len = 0;

	while (input[input_len] != '\0')
		input_len++;


			if ( div(input,input_len)== 0)
			{
				if (count>0)
					return 0;
				else
					return -1;
			}
			else
			{
				
				if (count % 2 == 0 && input_len % 2 != 0)
					return 0;
									
				if (count % 11 == 0 && input_len % 2 == 0)
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
			res = div11(test[i].input, test[i].count);
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
