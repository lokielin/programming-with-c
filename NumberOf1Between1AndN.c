//剑指offer：连续子数组的最大和
/*note:第一种方法改变数据顺序，一次性读入，不适合海量数据，但速度快
1. 枚举，n数组，有n(n+1)/2个子数组，算出每一个，0(n2)
2. 举例，找规律
*/
#include <stdio.h>
#include <stdlib.h>
void NumberOf1Between1AndN(int* num, int length);
void NumberOf1Between1AndN(int* num, int length)
{
	int i, temp,sum;
	if (num == NULL || length <= 0)
		return;
	sum = num[0];
	temp = num[0];
	for(i = 1; i < length ; i ++ )
	{
		sum += num[i];
		if (sum < num[i])
			sum = num[i];	
		if (sum > temp)
			temp = sum;
	}
	printf("%d",temp);
}
int main()
{
	int length = 8;
	int num[] = { 1,-2,3,10,-4,7,2,-5 };
	NumberOf1Between1AndN(num,length);
	system("pause");
}
