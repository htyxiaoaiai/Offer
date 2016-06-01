左旋转字符串

题目描述

汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
是不是很简单？OK，搞定它！


//左旋转字符串
void MyReverse(char* str, int left, int right)
{
	assert(str);
	while (left < right)
	{
		swap(str[left], str[right]);
		left++;
		right--;
	}
}
//三步反转法，解决字符串的旋转
string LeftRotateString(string str, int n)
{
	assert(n >= 0);
	string ret = str;
	char* rote = (char*)ret.c_str();
	if (ret.size() > 0 && n < ret.size())
	{
		MyReverse(rote, 0, n - 1);
		MyReverse(rote, n, ret.size() - 1);
		MyReverse(rote, 0, ret.size() - 1);
	}
	return ret;
}

void LeftRotateString()
{
	string s = "abcXYZdef";
	cout << LeftRotateString(s, 3) << endl;
}
