//剑指offer：顺时针打印数组
/*note:
1. 二维数组的调用不能用int **num，切记!!!
可以用int num[][MaxSize]，或者申请内存后用int **
*/
#include <stdio.h>
#define MaxSize 10

void PrintMatricClockwisely(int numbers[][MaxSize], int columns, int rows)
{
	int i, j, k, MaxCircle;
	if (columns < rows)
		MaxCircle = (columns) / 2;
	else
		MaxCircle = (rows) / 2;
	for (k = 0; k < MaxCircle; k++)
	{
		for (i = k, j = k; j < columns - k; j++)
			printf("%d", numbers[i][j]);
		for (i = i + 1, j = j - 1; i < rows - k; i++)
			printf("%d", numbers[i][j]);
		for (i = i - 1, j = j - 1; j > k - 1; j--)
			printf("%d", numbers[i][j]);
		for (i = i - 1, j = j + 1; i > k; i--)
			printf("%d", numbers[i][j]);
	}
}
int main()
{
	int n, m, i, j,k,MaxCircle;
	int num[10][10] = { 0 };
	scanf("%d %d",&n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &(num[i][j]));	
	PrintMatricClockwisely(num,  m,  n);
}
