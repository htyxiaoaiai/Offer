题目描述

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减序列的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。

//顺序查找中最小的元素
int FindMin(vector<int>rotateArray, size_t left, size_t right)
{
	int min = rotateArray[left];
	for (size_t i = left + 1; i <= right; i++)
	{
		if (min > rotateArray[i])
		{
			min = rotateArray[i];
		}
	}
	return min;//返回最小值
}

//在非递减数组的旋转序列中查找最下的元素
int minNumberInRotateArray(vector<int> rotateArray)
{
	size_t size = rotateArray.size();//计算数组的大小
	if (size == 0)
	{
		return -1;//数组为空
	}

	size_t left = 0;//从前往后遍历
	size_t right = size - 1;//从后往前遍历
	size_t mid = left;//当第一个元素为最小时则mid直接为left;

	while (rotateArray[left] >= rotateArray[right])
	{
		if (right - left == 1)
		{
			return rotateArray[right];//返回最小值
		}

		//二分查找
		mid = (left + right) / 2;
		//三个下标对应的元素相等例如1 0 1 1 1此时则需要从前往后顺序查找
		if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid])
		{
			return FindMin(rotateArray, left, right);
		}

		if (rotateArray[mid] >= rotateArray[left])
		{
			left = mid;
		}
		else if (rotateArray[mid] <= rotateArray[right])
		{
			right = mid;
		}
	}
	return rotateArray[mid];
}

void TestminNumberInRotateArray()
{
	vector<int> array1 = { 3,4,5,1,2 };
	cout << minNumberInRotateArray(array1) << endl;
	vector<int> array2 = { 1,2,3,4,5 };
	cout << minNumberInRotateArray(array2) << endl;
	vector<int> array3 = { 1,0,1,1,1 };
	cout << minNumberInRotateArray(array3) << endl;
}
