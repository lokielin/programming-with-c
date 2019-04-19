//剑指offer：打印1到最大的n位数
/*note:
1. 大数；
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void PrintToMaxOfNDigits(int n);
char* inv(char* num, int j);
int main()
{
	int n;
	scanf_s("%d", &n);
	PrintToMaxOfNDigits(n);
	system("pause");
}
void PrintToMaxOfNDigits(int n)
{
	int i = 1, j, k;
	char* num;
	num = (char*)malloc((n + 2) * sizeof(char));
	memset(num, '0', n + 1);
	num[n] = '2';
	num[n + 1] = '\0';
	while (1)
	{
		k = i++;
		
		j = 0;
		num[j++] = k % 10 + '0';
		while ((k /= 10) != 0)
			num[j++] = k % 10 + '0';
		if (num[n] != '2')
			break;
		num = inv(num, j - 1);
		k = 0;
		/*for(k = 0; k < j; k ++)
			printf("%c", num[k++]);
		k = 0;*/
		if (num[0] == '0')
		{
			k++;
			while (num[k++] == '0');
		}
		while (k < j)
			printf("%c", num[k++]);
		printf("\n");
	}
	free(num);
}
char* inv(char* num, int j)
{
	int i = 0;
	char temp;
	while (i < j - i)
	{
		temp = num[i];
		num[i] = num[j - i];
		num[j - i] = temp;
		i++;
	}
	return num;
}
