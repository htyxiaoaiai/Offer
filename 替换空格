题目描述

请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

//替换空格
void replaceSpace(char *str, int length) {
	//断言
	assert(str);
	int space = 0;
	int i = 0;
	int len = strlen(str);
	for (i = 0; i<len; i++)
	{
		if (str[i] == ' ')
		{
			space++;
		}
	}//计算空格的个数

	int NewLength = len + space * 2 + 1;//替换后的字符串空间

	if (NewLength > length)
	{
		return;//字符数组空间不够
	}
	else
	{
		char* oldS = str + len;
		char* newS = str + NewLength - 1;
		while (oldS != newS)
		{
			//替换
			if (*oldS == ' ')
			{
				*(newS--) = '0';
				*(newS--) = '2';
				*(newS--) = '%';
				oldS--;
			}
			else
			{
				*(newS--) = *(oldS--);
			}
		}
	}
}

void TestReplaceSpace()
{
	char str[20] = "We Are Happy.";
	replaceSpace(str, 20);
	cout << str << endl;
}
