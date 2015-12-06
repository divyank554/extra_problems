#include<stdio.h>
int main() 
	{
		int n;
		printf("enter number of lines\n");
		scanf("%d",&n);
		FILE *fp1 = fopen("test.txt", "r");
		FILE *fp2 = fopen("test.txt", "r");
		if (fp1 == NULL || fp2 == NULL)
		 {
			printf("no such file\n");
			return 1;
		}

		 int len = 100;
		char line[len];
		int count = 0;
		while(fgets(line,len,fp1) != NULL)
		{
			if (count < n)
				count++;
			else
			fgets(line,len,fp2);
		}

		if (count < n) 
		{
			printf("less than %d lines in the file\n",n);
			return 1;
		}
		
		printf("file contents\n");
		while (fgets(line,len,fp2) != NULL)
		printf("%s", line);

		fclose(fp1);
		fclose(fp2);
		return 0;
	}

