题目描述

统计一个数字在排序数组中出现的次数。

//数字在排序数组中出现的次数
//找到第一个k
int GetFirstK(vector<int>& data, int start, int end, int k)
{
	if (start > end)
	{
		return -1;
	}
	int mid = (start + end) / 2;
	int prev = mid - 1;
	if (data[mid] == k)
	{
		if ((prev > -1 && data[prev] != k) || mid == 0)
		{
			return mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	else if (data[mid] > k)
	{
		end = mid - 1;
	}
	else
	{
		start = mid + 1;
	}
	return GetFirstK(data, start, end, k);
}
//找到最后一个个出现的k
int GetLastK(vector<int>& data, int start, int end, int k)
{
	if (start > end)
	{
		return -1;
	}
	int mid = (start + end) / 2;
	int next = mid + 1;
	if (data[mid] == k)
	{
		if ((next < data.size() && data[next] != k) || mid == data.size() - 1)
		{
			return mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	else if (data[mid] > k)
	{
		end = mid - 1;
	}
	else
	{
		start = mid + 1;
	}
	return GetLastK(data, start, end, k);
}

int GetNumberOfK(vector<int> data, int k)
{
	int number = 0;
	if (data.empty())
	{
		return 0;
	}
	int first = GetFirstK(data, 0, data.size() - 1, k);
	int last = GetLastK(data, 0, data.size() - 1, k);
	if (first > -1 && last > -1)
	{
		number = last - first + 1;
	}
	return number;
}
