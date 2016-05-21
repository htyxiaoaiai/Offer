题目描述

把只包含因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

//丑数
//三个数中最小的值
int Min(int a, int b, int c)
{
	int min = (a < b) ? a : b;
	min = (min < c) ? min : c;
	return min;
}

int GetUglyNumber_Solution(int index)
{
	if (index <= 0)
	{
		return 0;
	}
	int * uglyNumber = new int[index];
	uglyNumber[0] = 1;
	int nextUgly = 1;
	//使用指针或者下标都可以
	int *mulUgly2 = uglyNumber;
	int *mulUgly3 = uglyNumber;
	int *mulUgly5 = uglyNumber;

	while (nextUgly < index)
	{
		//比当前最大的值uglyNumber大的三个数中选择最小的
		int min = Min(*mulUgly2 * 2, *mulUgly3 * 3, *mulUgly5 * 5);
		uglyNumber[nextUgly] = min;

		//找到第一个乘2比当前最大的值得下标
		while (*mulUgly2 * 2 <= uglyNumber[nextUgly])
		{
			mulUgly2++;
		}
		//找到第一个乘3比当前最大的值得下标
		while (*mulUgly3 * 3 <= uglyNumber[nextUgly])
		{
			mulUgly3++;
		}
		//找到第一个乘3比当前最大的值得下标
		while (*mulUgly5 * 5 <= uglyNumber[nextUgly])
		{
			mulUgly5++;
		}
		nextUgly++;
	}
	int ugly = uglyNumber[index - 1];
	delete[] uglyNumber;
	return ugly;
}
