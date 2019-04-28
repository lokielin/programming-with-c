//剑指offer：树的子结构
/*note: 
1. 能用递归用递归
2. 剑指未考虑一个跟结点只有叶子情况
*/
struct BinaryTreeNode
{
	int 			m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
}
void MirrorRecursively(BinaryTreeNode* pRoot)
{
	BinaryTreeNode* temp;
	if(pRoot == NULL)
		return;
	if(pRoot->m_pLeft)
	{
		if(pRoot->m_pRight)
		{
			temp = pRoot->m_pLeft;
			pRoot->m_pLeft = pRoot->m_pRight;
			pRoot->m_pRight = temp;
		}
		else
		{
			pRoot->m_pRight = pRoot->m_pLeft;
			pRoot->m_pLeft = NULL;
		}
		MirrorRecursively(pRoot->m_pRight);
	}
	if(pRoot->m_pRight)
	{
		if(pRoot->m_pLeft)
		{
			temp = pRoot->m_pRight;
			pRoot->m_pRight = pRoot->m_pLeft;
			pRoot->m_pLeft = temp;
		}
		else
		{
			pRoot->m_pLeft = pRoot->m_pRight;
			pRoot->m_pRight = NULL;
		}
		MirrorRecursively(pRoot->m_pLeft);
	}
}
