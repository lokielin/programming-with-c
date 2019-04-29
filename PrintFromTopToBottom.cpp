//剑指offer：从上往下打印二叉树
/*note:
1. std::deque<> dequeTree;这个还是要用c++吗
*/
stract BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode*	m_pLeft;
	BinaryTreeNode*	m_pRight;
}
void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
	if(!pTreeRoot)
		return;
	std::deque<BinaryTreeNode*> dequeTreeNode;
	dequeTreeNode.push_back(pTreeRoot);
	while(dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.push_front();
		printf("%d",pNode->m_nValue);
		if(pNode->m_pLeft)
			dequeTreeNode.push_back(pNode->m_pLeft);
		if(pNode->m_pRight)
			dequeTreeNode.push_back(pNode->m_pRight);
	}
}
