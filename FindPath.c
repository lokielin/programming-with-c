//剑指offer：二叉树中和为某一值的路径
/*note:
1. 用std::vector<int> path代替栈，因为栈只有top，我们需要所有
2. 要写个示例，发现是栈+根结点遍历->前序遍历
*/

typedef BinaryTreeNode* TreeNode;
struct BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode*	m_pLeft;
	BinaryTreeNode* m_pRight;
};
void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if(pRoot == NULL)
		return;
	std::vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
}
//这里应该是引用
void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int& currentSum)
{
	currentSum+= pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);
	boolt isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
	if(currentSum == expectedSum && isLeaf)
	{
		printf("A path is found: ")
		std::vector<int>::iterator iter = path.begin();
		for(;iter != path.end(); ++ iter)
			printf("%d\t",*iter);
		printf("\n");
	}
	if(pRoot-<m_pLeft != NULL)
		FindPath(pRoot->m_pLeft,expectedSum,path,currentSum);
	if(pRoot-<m_pRight != NULL)
		FindPath(pRoot->m_pRight,expectedSum,path,currentSum);
	currentSum -= pRoot->m_nValue;
	path.pop_back();
}	
