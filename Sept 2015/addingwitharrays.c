#include<stdio.h>
void reverse(char *p, int length)
{
	int i;
	char temp;
	for (i = 0; i < length / 2; i++)
	{
		temp = p[i];
		p[i] = p[length - i - 1];
		p[length - i - 1] = temp;
	}
}

void sum1(char *input1, char *input2, int temp_len)
{
	int sum,i;
	int carry=0;
		for (i = 0; i < temp_len; i++)
		{
				if (input2[i] != '\0')
				{
					sum = input1[i] - '0' + input2[i] - '0' + carry;
					carry=0;
					if (sum >= 10)
					{
						input1[i] = (sum - 10) + '0';
						carry = 1;
						if(i==temp_len-1)
								input1[i+1]='1';
					}
					else
						input1[i] = (sum +carry ) + '0';
				}
				else 
				{
					if(input1[i] == '9' && carry==1)
						{
							input1[i]='0';
							carry=1;
							if(i==temp_len-1)
								input1[i+1]='1';
						}
					  else
					  {
					  	input1[i] = ( (input1[i] - '0') + carry )	+ '0';
					  	carry = 0;
				}
			}
		}
		int length = 0;
		while (input1[length] != '\0')
			length++;
		
		reverse(input1, length);

		printf("\n****final sum : %s****\n", input1);
}

void sum2(char *input1, char *input2, int input1_len , int input2_len)
{
	int sum, carry=0 ;
	int i=input1_len-1 , temp_len=input1_len;
	int j=input2_len-1;
	while(i != -1 )
	{
			if (j != -1)
			{
	
		sum = input1[i] - '0' + input2[j] - '0' + carry;
		carry = 0;
		if(sum >= 10)
		{
			carry=1;
			input1[i] = (sum - 10) + '0';
			j--;
		}
		else
		 {
				input1[i] = sum + '0';
					j--;
				}
		}
		else if(input1[i] == '9' && carry==1)
						{
							input1[i]='0';
							carry=1;
						}
						 else
						 {
					  		input1[i] = ( (input1[i] - '0') + carry )	+ '0';
							carry = 0;
					    }
					i--;
	}
		if(carry==1)
		 {
	 		for (i = temp_len; i > 0; i--)
				input1[i] = input1[i-1];
					input1[0] = '1';
			}
			printf("\n****final sum : %s****\n", input1);
	}
	
void main()
{
		char input1[10000];
		char input2[10000];
		int input1_len = 0, input2_len = 0;
		int op, temp_len;
		printf("enter the number1\n");
		scanf("%s", &input1);

		while (input1[input1_len] != '\0')
			input1_len++;
			
		printf("enter the number2\n");
		scanf("%s", &input2);

		while (input2[input2_len] != '\0')
			input2_len++;	
			
		if(input1_len >= input2_len)
			temp_len = input1_len;
		else
			temp_len = input2_len;
		printf(" method 1 : using reverse function\n ");
		
		printf(" method 2 : using shift function\n ");
		
		printf("enter method : ");
		scanf("%d",&op);
	
		if(op == 1)
			{
				reverse(input1, input1_len);
				reverse(input2, input2_len);
				if(input1_len >= input2_len)
					sum1(input1, input2,input1_len);
				else
					sum1(input2, input1, input2_len);
			}
		else if(op == 2)
		{
				if(input1_len >= input2_len)
					sum2(input1, input2, input1_len , input2_len);
				else
					sum2(input2, input1, input2_len , input1_len);
		}
}
