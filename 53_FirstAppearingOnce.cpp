题目描述

请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。 

输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。

class Solution
{
public:
	Solution()
	{
		for (size_t i = 0; i < 256; i++)
		{
			_hash[i] = 0;
		}
	}

	void Insert(char ch)
	{
		_vec.push_back((unsigned char)ch);
		_hash[(unsigned char)ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		for (size_t i = 0; i < _vec.size(); i++)
		{
			if (_hash[_vec[i]] == 1)
			{
				return _vec[i];
			}
		}
		return '#';
	}
private:
	vector<unsigned char> _vec;
	int _hash[256];

};
