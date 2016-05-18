题目描述

输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323

//把数组排成最小的数
//比较两个字符串
//自定义的str的大小，如果str1+str2<str2+str1z,则认为str1<str2。
//str1+str2>str1+str1 则认为str1>str2
//str1+str2==str1+str2 则认为str1==str2

bool compare(const string& str1, const string& str2)
{
	return str1 + str2 < str2 + str1;
}
string PrintMinNumber(vector<int> numbers)
{
	string min;
	//数组为空
	if (numbers.empty())
	{
		return min;
	}
	int size = numbers.size();
	//将所有的数字转换为字符串，并且存储到v中
	vector<string> v;
	for (int i = 0; i < size; i++)
	{
		//字符串流
		//头文件<sstream>
		stringstream ss;
		//将numbers[i]放入输入流
		ss << numbers[i];
		//将其转换为字符串类型
		string s = ss.str();
		v.push_back(s);
	}

	//将字符串顺序表排序
	sort(v.begin(), v.end(), compare);
	//排序完成之后，将其放入字符串中
	for (int i = 0; i < size; i++)
	{
		min += v[i];
	}
	return min;
}
