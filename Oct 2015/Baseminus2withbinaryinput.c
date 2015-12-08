#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void main()
{
	while (1)
	{
		char input[100];
		printf("\nenter the binary base 2 number\n"); // binary input
		scanf("%s", &input);
		int length = 0;
		while (input[length] != '\0')
			length++;

		int carry = 0;
		int temp_len = length, i;

		while (length > 0)
		{
			int temp = length - 2;
			int count = 0;

			if (input[temp] == '1')
			{
				carry = 1;
				while (carry != 0 && temp >= 0)
				{

					if (temp == 0)
					{
						if (length == temp + 2)
							carry = 1;
						else
						{
							input[temp] = '0';
							carry = 1;
						}
					}
					else
					{

						input[temp - 1] = (carry ^ (input[temp - 1] - '0')) + '0';

						if (input[temp - 1] == '0')
							carry = 1;
						else
							carry = 0;
					}

					temp--;
				}

				if (carry == 1)
				{
					count = 1;
					for (i = temp_len; i > 0; i--)
						input[i] = input[i - 1];
					input[0] = '1';
				}

			}

			if (count == 1 && input[temp] != '1')
			{
				length = length - 1;
				temp_len++;
			}
			else
				length = length - 2;
		}
		input[temp_len] = '\0';
		printf("\nresult : %s\n", input);
		getch();
	}
}
