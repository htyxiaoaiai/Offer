题目描述

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。

//数组中的逆序对
int _InversePairs(vector<int>& data, vector<int> &copy, int start, int end)
{
	//数组被拆分的只剩下一个元素
	if (start == end)
	{
		return 0;
	}


	//数组拆分后的长度
	int length = (end - start) / 2;
	//将数组拆分到两个元素一组
	int left = _InversePairs(data, copy, start, start + length);
	int right = _InversePairs(data, copy, start + length + 1, end);

	int forIdx = start + length;//前半段的结束下标
	int backIdx = end;//后半段结束的下标
	int copyEnd = end;//copy数组的下标
	int count = 0;
	while (forIdx >= start&&backIdx >= start + length + 1)
	{
		if (data[forIdx] > data[backIdx])
		{
			copy[copyEnd--] = data[forIdx--];
			count += (backIdx - start - length);
		}
		else
		{
			copy[copyEnd--] = data[backIdx--];
		}
	}

	//将剩余的有序的数组归位
	for (; forIdx >= start; forIdx--)
	{
		copy[copyEnd--] = data[forIdx];
	}
	for (; backIdx >= start + length + 1; backIdx--)
	{
		copy[copyEnd--] = data[backIdx];
	}

	//更新data将已经排好序的copy复制
	for (int i = start; i <= end; i++)
	{
		data[i] = copy[i];
	}

	return left + right + count;
}

int InversePairs(vector<int> data) {
	if (data.empty())
	{
		return 0;
	}
	vector<int> copy(data);//data的副本
	return _InversePairs(data, copy, 0, data.size() - 1);
}
