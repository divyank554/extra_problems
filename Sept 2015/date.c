#include<stdio.h>
struct testcases
{
	char input[10];// date format is fixed
} test[10] = {
	{ { "31/08/1915" } },
	{ { "28/05/1901" } },
	{ { "29/02/1900" } },
	{ { "29/02/2000" } },
	{ { "29/02/2000" } },
	{ { "27/02/1900" } },
	{ { "32/01/5001" } },
	{ { "02/12/2015" } },
	{ { "21/11/1753" } },
	{ { "05/11/1995" } },

};
int valid(char *input)
{

	int year = 0;
	int i;
	for (i = 6; i < 10; i++)
	{
		if (i == 6)
			year = year + ((input[6] - '0') * 1000);
		if (i == 7)
			year = year + ((input[7] - '0') * 100);
		if (i == 8)
			year = year + ((input[8] - '0') * 10);
		if (i == 9)
			year = year + (input[9] - '0');
	}
	int month = 0;
	for (i = 3; i < 5; i++)
	{
		if (i == 3)
			month = month + ((input[3] - '0') * 10);
		if (i == 4)
			month = month + (input[4] - '0');
	}

	int day = 0;
	for (i = 0; i < 2; i++)
	{
		if (i == 1)
			day = day + (input[1] - '0');
		if (i == 0)
			day = day + ((input[0] - '0') * 10);

	}
	int flag = 0;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day > 0 && day < 32)
			flag = 1;
		else
			flag = 0;
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 0 && day < 31)
			flag = 1;
		else
			flag = 0;
	}

	if (month == 2)
	{
		if (year % 400 == 0)
		{
			if (day > 0 && day < 30)
				flag = 1;
			else
				flag = 0;
		}
		else if (year % 100 == 0)
		{
			if (day > 0 && day < 30)
				flag = 0;
			else
				flag = 1;
		}

		else
			if (year % 4 == 0)
			{
				if (day > 0 && day < 30)
					flag = 1;
				else
					flag = 0;
			}
			else
			{
				if (day > 0 && day < 29)
					flag = 1;
				else
					flag = 0;
			}
	}
	return flag;
}

void  dateineng(char *b)
{
	int res = valid(b);
	char temp = b[1];
	if (res == 1)
	{
		switch (temp)
		{
		case '0': if (b[0] == '1')
			printf("tenth ");
				  else if (b[0] == '2')
					  printf("twenty ");
				  else if (b[0] == '3')
					  printf("thirty ");
				  break;
		case '1': if (b[0] == '0')
			printf("first ");
				  else if (b[0] == '1')
					  printf("eleventh ");
				  else if (b[0] == '2')
					  printf("twenty first ");
				  else if (b[0] == '3')
					  printf("thirty first ");
				  break;
		case '2': if (b[0] == '0')
			printf("second ");
				  else if (b[0] == '1')
					  printf("twelveth ");
				  else if (b[0] == 2)
					  printf("twenty second ");
				  break;
		case '3': if (b[0] == '0')
			printf("third ");
				  else if (b[0] == '1')
					  printf("thirteenth ");
				  else if (b[0] == '2')
					  printf("twenty third ");
				  break;
		case '4': if (b[0] == '0')
			printf("forth ");
				  else if (b[0] == '1')
					  printf("forteenth ");
				  else if (b[0] == '2')
					  printf("twenty forth ");
				  break;
		case '5': if (b[0] == '0')
			printf("fifth ");
				  else if (b[0] == '1')
					  printf("fifteenth ");
				  else if (b[0] == '2')
					  printf("twenty fifth ");
				  break;
		case '6': if (b[0] == '0')
			printf("sixth ");
				  else if (b[0] == '1')
					  printf("sixteenth ");
				  else if (b[0] == '2')
					  printf("twenty sixth ");
				  break;
		case '7': if (b[0] == '0')
			printf("seventh ");
				  else if (b[0] == '1')
					  printf("seventeenth ");
				  else if (b[0] == '2')
					  printf("twenty seventh ");
				  break;
		case '8': if (b[0] == '0')
			printf("eighth ");
				  else if (b[0] == '1')
					  printf("eighteenth ");
				  else if (b[0] == '2')
					  printf("twenty eighth ");
				  break;
		case '9': if (b[0] == '0')
			printf("ninth ");
				  else if (b[0] == '1')
					  printf("ninteenth ");
				  else if (b[0] == '2')
					  printf("twenty ninth ");
				  break;

		}

		int temp2 = b[4];

		switch (temp2)
		{
		case '0': if (b[3] == '1')
			printf(" october ");
			break;
		case '1': 	if (b[3] == '1')
			printf(" november ");
			if (b[3] == '0')
				printf(" january ");
			break;

		case '2': 	if (b[3] == '0')
			printf(" febuary ");
			if (b[3] == '1')
				printf(" december ");
			break;

		case '3': if (b[3] == '0')
			printf(" march ");
			break;

		case '4': if (b[3] == '0')
			printf(" april ");
			break;

		case '5': if (b[3] == '0')
			printf(" may ");
			break;

		case '6': if (b[3] == '0')
			printf(" june ");
			break;

		case '7': if (b[3] == '0')
			printf(" july ");
			break;

		case '8': if (b[3] == '0')
			printf(" august ");
			break;

		case '9': if (b[3] == '0')
			printf(" september ");
			break;
		}

		int temp3 = b[6];

		switch (temp3)
		{

		case '1': printf("one thousand ");
			break;

		case '2': 	printf("two thousand ");
			break;

		case '3': 	printf("three thousand ");
			break;

		case '4':  printf("four thousand ");
			break;

		case '5': 	printf("five thousand ");
			break;

		case '6': 	printf("six thousand ");
			break;

		case '7': 	printf("seven thousand ");
			break;

		case '8': 	printf("eight thousand ");
			break;

		case '9': 	printf("nine thousand ");
			break;
		}

		int temp4 = b[7];

		switch (temp4)
		{

		case '1': printf("one hundred ");
			break;

		case '2': 	printf("two hundred ");
			break;

		case '3': 	printf("three hundred ");
			break;

		case '4':  printf("four hundred ");
			break;

		case '5': 	printf("five hundred ");
			break;

		case '6': 	printf("six hundred ");
			break;

		case '7': 	printf("seven hundred ");
			break;

		case '8': 	printf("eight thousand ");
			break;

		case '9': 	printf("nine hundred ");
			break;
		}

		int temp5 = b[8];

		if (b[8] == '1') {

			switch (temp5)
			{
			case '1':  if (b[9] == '1')
				printf("and eleven ");
					   else if (b[9] == '2')
						   printf("and twelve ");
					   else if (b[9] == '3')
						   printf("and thirteen ");
					   else if (b[9] == '4')
						   printf("and forteen ");
					   else if (b[9] == '5')
						   printf("and fifteen ");
					   else if (b[9] == '6')
						   printf("and sixteen ");
					   else if (b[9] == '7')
						   printf("and seventeen ");
					   else if (b[9] == '8')
						   printf("and eighteen ");
					   else if (b[9] == '19')
						   printf("and ninteen ");

			}
		}

		switch (temp5)
		{
		case '0': if (b[7] != '0')
			printf(" and ");
			break;

		case '1': if (b[9] == 0)
			printf("and ten ");
			break;

		case '2': 	printf("and twenty ");
			break;

		case '3': 	printf("and thirty ");
			break;

		case '4':  printf("forty ");
			break;

		case '5': 	printf("and fifty ");
			break;

		case '6': 	printf("and sixty ");
			break;

		case '7': 	printf("and seventy ");
			break;

		case '8': 	printf("and eighty ");
			break;

		case '9': 	printf("and ninty ");
			break;
		}

		int temp6 = b[9];

		if (b[8] != '1') {

			switch (temp6)
			{
			case '1': printf("one ");
				break;

			case '2': 	 printf("two ");
				break;

			case '3': 	 printf("three ");
				break;

			case '4':  printf("four ");
				break;

			case '5': 	printf("five ");
				break;

			case '6': 	 printf("six ");
				break;

			case '7': 	 printf("seven ");
				break;

			case '8': 	 printf("eight ");
				break;

			case '9': 	  printf("nine ");
				break;
			}
		}
	}
	else printf(" invalid date ");
	getchar();
}


void Tests(int n_tests)
{
	int i;
	for (i = 0; i < n_tests; i++)
		dateineng(test[i].input);
}

int main()
{
	int n_tests = 10;
	Tests(n_tests);
	getchar();
}
