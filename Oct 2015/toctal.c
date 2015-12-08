#include<stdio.h>
void main()
    {
        while(1){
        char input[100];
        char res[10];
        printf("enter the number in binary ");
        scanf("%s",&input);
        int sum = 0,i=0,j=1,length=0,m ,count=1 ;
        while(input[length]!='\0')
           length++;
        printf("\nlength : %d \n",length);
        if(length % 3 == 2 )
        {
           for(m=length ; m>0 ; m--)
                input[m] = input[m-1];
           input[0] = '0';
                length++;
        }
        else if(length % 3 == 1)
        {
           for(m=length+1 ; m>1 ; m--)
                input[m] = input[m-2];
           input[0] = '0';
           input[1] = '0';
                length = length + 2;
        }
        i = length / 3;
        while(length!=-1)
        {
           sum = sum +((input[length-1] - '0') * j);
           j = j * 2;
           if(count == 3)
            {
                printf("\nsum %d \n",sum);
                res[i-1] = sum + '0';
                i--;
                sum = 0;
                j=1;
                count = 0;
          }
           length--;
           count++;
        }

        printf("\nbinary number in  octal number : %s\n", res);
    }
}
