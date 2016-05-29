题目描述

小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck! 

输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
void InsertRet(int begin, int end, vector<vector<int> >&ret)
{
	vector<int> tmp;
	for (int i = begin; i <= end; i++)
	{
		tmp.push_back(i);
	}
	ret.push_back(tmp);
}

vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int>>  ret;
	if (sum < 3)
	{
		return ret;
	}
	int small = 1;
	int big = 2;
	int curSum = small + big;
	//切记要加1，否则会少算一个数据
	int midle = (1 + sum) / 2;
	while (small < midle)
	{
		if (curSum == sum)
		{
			InsertRet(small, big, ret);
		}
		while (curSum > sum)
		{
			curSum -= small;
			small++;
			if (curSum == sum && small < midle)
			{
				InsertRet(small, big, ret);
			}
		}

		big++;
		curSum += big;
	}
	return ret;
}
