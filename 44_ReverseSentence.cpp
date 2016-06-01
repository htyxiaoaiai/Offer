
题目描述

牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

//反转单词
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
//翻转单词顺序列
//1、将每个单词反转
//2、将整个字符反转
string ReverseSentence(string str)
{
	string ret = str;
	int size = ret.size();
	char* cStr = (char*)ret.c_str();

	int begin = 0;
	int end = 0;
	for (size_t index = 0; index < size;)
	{
		begin = index;
		//防止越界访问
		while (index < size&&str[index] != ' ')
		{
			index++;
		}

		end = index - 1;
		//跳过空格
		index++;

		MyReverse(cStr, begin, end);
	}
	MyReverse(cStr, 0, size - 1);
	return ret;
}

void TestReverseSentence()
{
	string str = " student. a am I";
	cout << ReverseSentence(str) << endl;
}
