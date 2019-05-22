//剑指offer：数组中出现次数超过一半的数字
/*note:第一种方法改变数据顺序，一次性读入，不适合海量数据，但速度快
1. O(n)的解法，基于快速排序思想
2. 二叉树中的大顶堆，在O(1)得到k个数中最大值，O(logk)完成删除和插入，但是构建最大堆需要时间，面试可能来不及
3. 用STL中红黑树，比如set和multiset（没有写，187页）
*/
void GetLeastNumbers(int* input, int n, int* output, int k)
{
	int index,start, end,i;
	if (input == NULL || n <= 0 || k <= 0)
		return;
	start = 0;
	end = n - 1;
	index = Partition(input, n, start, end);
	while (index != k - 1)
		if (index < k - 1)
			index = Partition(input, n, index - 1, end);
		else
			index = Partition(input, n, start, index + 1);
	for (i = 0; i <= index; i++)
		printf("%d",input[i]);
}
