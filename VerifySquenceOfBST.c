//剑指offer：二叉搜索树的后序遍历
/*note:
1. 
*/
bool VerifySquenceOfBST(int sequence[], int length)
{
	if(sequence == NULL || lengt <= 0)
		return false;
	int root = sequence[length - 1];
	int i = 0; 
	for(;i < length - 1; ++ i)
	{
		if(sequence[i] > root)
			break;
	}
	int j = i;
	for(; j < length - 1; ++j)
	{
		if(sequence[j] < root)
			return false;
	}
	bool left = true;
	if(i > 0)
		left = VerifySquenceOfBST(sequence,i);
	boor right = true;
	if(j < length - 1)
		right = VerifySquenceOfBST(sequence + i, length - i - 1);
	reuturn left && right);
}
