//剑指offer：复杂链表的赋复制
/*note:多种方法，这种最简单
1. 先复制正常链表，psibling = NULL,再每次查询当前节点psibling
2. 前面一样，然后哈希表配对，空间换时间
3. 在原节点后跟一个，，然后拆分
*/
struct ComplexListNode
{
	int 				m_nValue;
	ComplexListNode*	m_pNext;
	ComplexListNode*	m_pSibling;
}
void CloneNode(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	if(pHead == NULL)
		return NULL;
	while(pNode)
	{
		ComplexListNode* pClone = (ComplexListNode*)malloc(sizeof(ComplexListNode));
		pClone->m_nValue = pNode->m_nValue;
		pClone->m_pNext = pNode->m_pNext;
		pClone->m_pSibling = NULL;
		pNode->m_pNext = pClone;
		pNode = pClone->m_pNext;		
	}	
}
void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while(pNode)
	{
		ComplexListNode* pClone = pNode->m_pNext;
		if(pNode->m_pSibling != NULL)
			pClone->m_pSibling = pNode->m_pSibling->m_pNext;
		pNode = pClone->m_pNext;
	}
}
ComplexListNode* ReConnectNode(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	ComplexListNode* pCloneNode = NULL;
	ComplexListNode* pCloneHead = NULL;
	if(pNode)
	{
		pCloneHead = pCloneNode = pNode->m_pNext;
		pNode->m_pNext = pCloneHead->m_pNext;
		pNode = pClone->m_pNext;		
	}
	while(pNode)
	{
		pCloneNode->m_pNext = pNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode ->m_pNext;
		pCloneNode = pCloneNode->m_pNext;
	}
	return pCloneHead;
}
ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNode(pHead);
	ConnectSiblingNodes(pHead);
	return ReConnectNode(pHead);
	
}
