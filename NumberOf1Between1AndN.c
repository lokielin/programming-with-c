//剑指offer：从1到n证书中1出现的次数
/*note:侧重算法
1. 算法一，每一个判断，时间效率低
2. 算法二，递归，还没写
*/
#include <stdio.h>
#include <stdlib.h>
int NumberOf1Between1AndN(unsigned int n);

int NumberOf1Between1AndN(unsigned int n)
{
	int i,temp,tempk,sum;
	sum = 0;
	while (i <= n)
	{
		temp = i;
		while (temp != 0)
		{
			tempk = temp % 10;
			temp /= 10;
			if (tempk == 1)
			{
				sum ++;
				break;
			}
		}
		i++;
	}
	return sum;
}
