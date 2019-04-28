//剑指offer：树的子结构
/*note: 
1. 能用递归用递归
2. 边界条件尤为重要
*/
struct BinaryTreeNode
{
	int 			m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
}
bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool Result = false;
	if(pRoot1 != NULL &&pRoot2 != NULL)
	{
		if(pRoot1->m_nValue == pRoot2->m_nValue)
			Result = DoesTree1HaveTree2(pRoot1,pRoot2);
		if(!Result)
			HasSubtree(pRoot1->m_pLeft,pRoot2);
		if(!Result)
			HasSubtree(pRoot1->m_pRight,pRoot2);
	}
	return Result;
	
}
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if(pRoot2 == NULL)
		return True;
	if(pRoot1 == NULL)
		return False;
	if(pRoot1->m_nValue != pRoot2->m_nValue)		
		return False;
	else 
		return DoesTree1HaveTree2(pRoot1->m_pLeft,pRoot2->m_pLeft)&&DoesTree1HaveTree2(pRoot1->m_pRight,pRoot2->m_pRight);
}
