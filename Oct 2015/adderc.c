#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void adder(char *number1, char *number2)
{
	int i = 0, carry = 0, sum = 0, temp;
	for (i = 0; number1[i] != '\0'; i++)
	{
		sum = number1[i] - '0' + number2[i] - '0' + carry;  
		carry = 0;
		if (i == 0 && sum>9)
		{
			printf("NOT POSSIBLE");
			exit(0);
		}
		else if (sum < 9)
		{
			number1[i] = sum + '0';
			temp = i;
		}
		else if (sum == 9)
			number1[i] = sum + '0';
		else if (sum > 9)
		{
			number1[i] = (sum - 10) + '0';
			carry = 1;
			int j = i - 1;
			int	count = 0;
			while (j != temp - 1)
			{
				if (number1[j] == '9')
				{
					number1[j] = '0';
					carry = 1;
					count++;
				}
				else if (number1[j] - '0' < 9)
				{
					number1[j] = (number1[j] - '0' + carry) + '0';
					carry = 0;
					count++;
				}
				j--;
			}
			temp = temp + count;
		}
	}
	number1[i] = '\0';
	printf("sum : %s\n", number1);

}

int main()
{
	while (1) {
		char number1[10000];
		char number2[10000];
		printf("enter the number1\n");
		scanf("%s", &number1);
		printf("enter the number2\n");
		scanf("%s", &number2);
		adder(number1, number2);
		getch();
	}
}