题目描述

输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。 

输出描述:
对应每个测试案例，输出两个数，小的先输出。

vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
	vector<int> ret;
	if (array.size() < 2)
	{
		return ret;
	}
	size_t size = array.size();
	size_t small = 0;
	size_t big = size - 1;
	int before = INT_MAX;
	while (small < big)
	{
		int curSum = array[small] + array[big];
		if (curSum == sum)
		{
			if (array[small] * array[big] < before)
			{
                before=array[small] * array[big];
				ret.clear();
				ret.push_back(array[small]);
				ret.push_back(array[big]);	
			}
			small++;
			big--;
		}
		else if (curSum > sum)
		{
			big--;
		}
		else
		{
			small++;
		}
	}
	return ret;
}
