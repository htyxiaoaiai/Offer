题目描述

在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符的位置。
若为空串，返回-1。位置索引从0开始

//代码1
//第一个只出现一次的字符的位置
int FirstNotRepeatingChar(string str) {
	//字符串不能为空
	if (str.empty())
	{
		return -1;
	}
	int *count = new int[256];
	int size = str.size();

	//计数器初始值赋为0
	for (int i = 0; i < size; i++)
	{
		count[i] = 0;
	}

	//记录每个字符出现的次数
	for (int i = 0; i < size; i++)
	{
		count[str[i]]++;
	}

	//按照字符串的顺序来查找
	for (int i = 0; i < size; i++)
	{
		if (count[str[i]] == 1)
		{
			return i;
		}
	}
	return -1;
}


//代码2
//第一个只出现一次的字符的位置
int FirstNotRepeatingChar(string str)
{
	if (str.size < 0)
	{
		return -1;
	}

	//申请256个空间并初始化为0
	vector<int> count(256, 0);
	size_t size = str.size();
	for (size_t i = 0; i < size; i++)
	{
		count[str[i]]++;
	}
	for (size_t i = 0; i < size; i++)
	{
		if (count[str[i]] == 1)
		{
			return i;
		}
	}
	return -1;
}
