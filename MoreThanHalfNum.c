//剑指offer：数组中出现次数超过一半的数字
/*note:中位数解法，数组特征加减，，，精妙的算法
1. 采用快速排序的思想
2. 保存数字，保存次数，相同+1，不同-1,0时重新保存并+1
*/
int MoreThanHalfNum(int* numbers, int length)
{
	int i, start, end, index,middle,result;
	start = 0; end = length - 1;
	middle = length >> 1;
	if (CheckInvalidArray(numbers, length))
		return 0;

	index = Partition(numbers, length, start, end);
	while (index != middle)
	{
		if (index > middle)
			Partition(numbers, length, start, index - 1);
		if (index < middle)
			Partition(numbers, length, index + 1, end);
	}
	result = numbers[middle];
	if (CheckMoreThanHalf(numbers, length, result))
		result = 0;
	return result;	
}
int CheckInvalidArray(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
		return 0;
	else
		return 1;
}
int CheckMoreThanHalf(int* numbers, int length, int result)
{
	int i,sum = 0;
	for (i = 0; i < length; i++)
		if (numbers[i] == result)
			sum++;
	if (sum < length >> 1)
		return 0;
	else
		return 1;
}
//方法二
int MoreThanHalfNum(int* numbers, int length)
{
	int i,result,times;
	if (CheckInvalidArray)
		return 0;
	result = numbers[0]; times = 1;
	for (i = 1; i < length; i++)
	{
		if (numbers == result)
			times++;
		else
			times--;
		if (times == 0)
		{
			result = numbers[i];
			times++;
		}
	}
	if (CheckMoreThanHalf(numbers, length, result))
		result = 0;
	return result;
}
