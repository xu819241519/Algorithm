#include <iostream>
#include <Windows.h>
using namespace std;
//Left shift the given string,the limited cost of time is O(n),the limited cost of space is O(1)

//Method 1: Shift string one by one, O(m*n)
void LeftShiftOneByOne(char * str,int m)
{
	for(int i=0;i<m;++i)
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

//Method 2.1: Shift string by turning over, m is the count of shifting,O(n-m + n%m*m)
void ShiftByTurningOver(char * str,int m)
{
	//cal the length of the string
	if(m==0)return ;
	int i=0;
	while(str[i++]!=0);
	int n=i-1;

	int pt1=0,pt2=m;
	int k=n/m-1;
	while(k--)
	{
		i=0;
		while(i<m)
		{
			swap(str[pt1],str[pt2]);
			pt1++;
			pt2++;
			i++;
		}
	}
	if(n%m!=0)
	{
		//move forward one by one
		//k=n%m;
		//while(k--)
		//{
		//	i=pt2;
		//	while(i>pt1)
		//	{
		//		swap(str[i],str[i-1]);
		//		i--;
		//	}
		//	pt1++;
		//	pt2++;
		//}

		//or using method 1
		LeftShiftOneByOne(&str[pt1],m);
	}
}

//method 2.2 Shift string by turning over
void ShiftByTurningOver2(char * str ,int m)
{
	//cal the length of the string
	if(m==0)return ;
	int i=0;
	while(str[i++]!=0);
	int n=i-1;

	int pt1=0,pt2=m;
	int k=n/m-1;
	while(k--)
	{
		i=0;
		while(i<m)
		{
			swap(str[pt1],str[pt2]);
			pt1++;
			pt2++;
			i++;
		}
	}
	if(n%m!=0)
	{
		i=0;
		while(pt2<n)
		{
			swap(str[pt1],str[pt2]);
			pt1++;
			pt2++;
			i++;
		}
		pt2-=i;
		//pt1到pt2-1所有的往前移动i个距离
		for(int j=pt1;j<pt2;++j)
		{
			for(int k=0;k<i;++k)
			{
				swap(str[j-k],str[j-k-1]);
			}
		}
		//举一个例子    
		//abcdefghijk    
		//当执行到这里的时候，defghiabcjk    
		//      pt1    pt2    
		//defghi a b c j k，a 与 j交换，jbcak，然后，pt1++，pt2++    
		//        pt1    pt2    
		//       j b c a k，b 与 k交换，jkcab，然后，pt1++，pt2不动，    
        
		//r = m - n % m= 3-11%3=1，即循环移位1次。    
		//          pt1  pt2    
		//       j k c a b    
		//p1所指元素c实现保存在temp里，    
		//然后执行此条语句：str[i] = str[i+1]; 即a跑到c的位置处，a_b    
		//i++，再次执行：str[i] = str[i+1]，ab_    
		//最后，保存好的c 填入，为abc，所以，最终序列为defghi jk abc。 
	}
}
//method 2.3 Shift string by turning over and with curision
//str is the string to be shift,n is the left count to be done ,m is the count to be shift,
//begin is the beginning of shifting string,end is the end of shifting string,
//flag represents  left shifting(true) or right shifting(false)
void ShiftStringByTurningOverWithCurision(char *str ,int n,int m,int begin,int end,bool flag)
{
	if(n==0 || m==0)
		return ;
	//left shifting
	if(flag)
	{
		int k=n/m-1;
		int pt1=begin;
		int pt2=begin+m;
		while(k--)
		{
			for(int i=0;i<m;++i)
				swap(str[pt1++],str[pt2++]);
		}
		ShiftStringByTurningOverWithCurision(str,n%m+(n%m==0?0:m),n%m,pt1,end,false);
	}
	//right shifting
	else
	{
		int k=n/m-1;
		int pt1=end-1;
		int pt2=pt1-m;
		while(k--)
		{
			for(int i=0;i<m;++i)
				swap(str[pt1--],str[pt2--]);
		}
		ShiftStringByTurningOverWithCurision(str,n%m+(n%m==0?0:m),n%m,begin,pt1,true);
	}
	
}
int main(int argc,char * argv[])
{
	char test[11]="abcdefghij";
	//LeftShiftOneByOne(test,2);
	//ShiftByTurningOver2(test,2);
	//ShiftStringByTurningOverWithCurision(test,10,8,0,10,true);
	cout<<test<<endl;
	system("pause");
}
