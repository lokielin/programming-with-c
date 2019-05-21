//剑指offer：字符串的排列
/*note:深入理解递归，
1. 分两步，固定第一个字符，求后面排列，再第一个字符交换后面
2. c++有函数重载，c不行
*/
void Permutation(char* pStr)
{
	if(pStr == NULL)
		return ;
	exPermutation(pStr, pStr);
}
void exPermutation(char* pStr, char* pBegin)
{
	char* pCh, temp;
	if(pBegin == NULL)
		printf("%s",pStr);
	for(pCh = pBegin;*pCh != '\0'; pCh ++)
	{
		temp = *pCh;
		*pCh = *pBegin;
		*pBegin = temp;
		exPermutation(pStr, pBegin + 1);
		temp = *pCh;
		*pCh = *pBegin;
		*pBegin = temp;
		
	}
}
