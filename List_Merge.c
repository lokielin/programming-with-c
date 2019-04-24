//剑指offer：合并两个排序的链表
/*note: 
1. 能用递归用递归
*/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if(pHead1 == NULL)
		return pHead2;
	else if(pHEad2 == NULL)
		return pHead1;
	ListNode* pMergedHead == NULL;
	if(pHead1->m_pValue < pHead2->m_pValue)
	{
		pMergedHead = pHead1>m_pValue;
		pHead1->m_pNext = pMergedHead(pHead1>m_pNext,pHead2);
	}
	else
	{
		pMergedHead = pHead2>m_pValue;
		pHead1->m_pNext = pMergedHead(pHead1,pHead2->m_pNext);
	}
	return pMergedHead;
}
