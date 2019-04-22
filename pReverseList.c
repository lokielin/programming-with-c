//剑指offer：反转链表
/*note: 
特殊用例
1. 表头是NULL
2. 只有一个结点
3. 多个结点
*/
ListNode* pReverseList(ListNode* pHead)
{
	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while(pNode != NULL)
	{
		ListNode* pNext = pNode->m_pNext;
		if(pNext == NULL)
		pReversedHead = pNode;
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversedHead;
}	
