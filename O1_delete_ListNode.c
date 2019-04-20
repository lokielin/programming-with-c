//剑指offer：O(1)删除链表结点
/*note: 
1. 把下一个结点复制到需删除结点，再删除下一个；
2. 若是尾结点，还需遍历一次；
3. 唯一一个结点，赋值NULL
*/
void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted)
{
	if(!pListHead||pToBeDeleted)
		return;
	if(pToBeDeleted->m_pNext != NULL)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_pValue = pNext->m_pValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		delete pNext;
		pNext = NULL;
	}
	else if(*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else
	{
		ListNode* pNode = *pListHead;
		while(pNode->m_pNext != pToBeDeleted)
			pNode = pNode->m_pNext;
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}
