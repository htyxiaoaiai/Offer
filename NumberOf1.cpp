题目描述

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

//二进制中1的个数
int  NumberOf1(int n) 
{
	int count = 0;
	while (n)
	{
		count++;
		n &= (n - 1);//每次去掉1个1
	}
	return count;
}

void TestNumberOf1()
{
	cout << NumberOf1(11) << endl;
}
