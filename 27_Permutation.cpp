题目描述

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 结果请按字母顺序输出。

输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

//字符串的排列
void _Permutation(vector<string>&ret, string str, int start)
{
	int size = str.size();
	//只剩下一个字符不需要交换
	if (start == size - 1)
	{
		ret.push_back(str);
	}
	else
	{
		for (int j = start; j < size; ++j)
		{
			//如果有相同的字符，当作是一个排列，注意j==start时放进去第一次，其余的则不需要放入
			if (j != start && str[start] == str[j])
			{
				continue;
			}
			//交换开始的字符和其他的字符
			swap(str[start], str[j]);
			//将字符分成两部分，第一个字符和剩余的字符构成另外一部分
			_Permutation(ret, str, start + 1);
		}
	}
}

vector<string> Permutation(string str) {
	//存储排序的序列
	vector<string> ret;
	if (str.size() > 0)
	{
		//开始的下标
		int start = 0;
		_Permutation(ret, str, start);
	}
	return ret;
}
