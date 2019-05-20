//剑指offer：二叉搜索树与双向链表
/*note:多种方法，这种最简单
1. 好好理解递归和中序遍历
2. 
3. 
*/
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
	BinaryTreeNode* pLastNodeInList = NULL;
	ConvertNode(pRootOfTree, &pLastNodeInList);
	
	BinaryTreeNode* pHeadOfList = pLastNodeInList;
	while(pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL)
		pHeadOfList = pHeadOfList->m_pLeft;
	return pHeadOfList;
}
void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
	if(pNode == NULL)
		return;
	BinaryTreeNode* pCurrent = pNode;
	if(pCurrent->m_pLeft != NULL)
		ConertNode(pCurrent->m_pLeft,pLastNodeInList);
	pCurrent->m_pLeft = *pLastNodeInList;
	if(*pLastNodeInList != NULL)
		(*pLastNodeInList)->m_pRight = pCurrent;
	*pLastNodeInList = pCurrent;
	if(pCurrent->m_pRight != NULL)
		ConertNode(pCurrent->m_pRight,pLastNodeInList);
}
