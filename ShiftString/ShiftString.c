#include <stdio.h>

//Left shift the given string,the limited cost of time is O(n),the limited cost of space is O(1)

//Method 1: Shift String One by One
void LeftShiftOneByOne(char * str,int n)
{
	for(int i=0;i<n;++i)
	{
		char temp=str[0];
		int j=0;
		while(str[j+1]!=0)
		{
			str[j]=str[j+1];
			++j;
		}
		str[j]=temp;
	}
}

int main(int argc,char * argv[])
{
	char test[11]="abcdefghij";
	LeftShiftOneByOne(test,2);
	printf("%s\n",test);
}
