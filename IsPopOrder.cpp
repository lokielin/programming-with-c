//剑指offer：栈的压入、弹出序列
/*note:
1. std::stack<int>stackData;这个还是要用c++吗
*/
#include <stdio.h>
#define MaxSize 10

bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
	bool bPossible = false;
	if(pPush != NULL && pPop != NULL && nLength != 0)
	{
		const int* pNextPush = pPuch;
		const int* pNextPop = pPop;
		std::stack<int>stackData;
		while(pNextPop - pPop < nLength)
		{
			while(statkData.empty() || stackData.top() != *pNextPop)
			{
				if(pNextPush - pPush == nLength)
					break;
				statckData.push(*pNextPush);
				pNextPush ++;
			}
			if(stackData.top() != *pNextPop)
				break;
			statckData.pop();
			pNextPop ++;
		}
		if(statkData.empty() && pNextPop - pPop == nLength)
			bPossible = true;
	}
	return bPossible;
}
