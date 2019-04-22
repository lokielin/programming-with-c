//剑指offer：二进制中1的个数
/*note: 
1. 与0x1,与0x1<1，以此类推；
2. 下面代码难理解一些，但能带来惊喜Org
*/
int NumberOf1(int n)
{
	int count = 0;
	while(n)
	{
		++count;
		n = (n - 1)&n;
	}
	return count;
}
