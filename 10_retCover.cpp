题目描述

我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

解法分析：
假设当n为1的时候，只有1种覆盖方法
当n>2时，覆盖大矩形的最左边时有2种覆盖方法：当竖着放的时候右边还剩下2*(n-1)个区域，此时的覆盖方法为f(n-1);
当横着放的时候，那么最左下角也必须横着放，那么右边还剩下2*（n-2）个矩形，此时的方法为f(n-2);
总的方法为f(n)=f(n-1)+f(n-2),又是斐波纳挈数列。

//矩形覆盖
long long retCover(size_t number)
{
	size_t cover[2] = { 0,1 };
	if (number < 2)
	{
		return cover[number];
	}

	long long coverOne = 1;
	long long coverTwo = 1;
	long long coverN = 0;
	for (size_t i = 2; i <= number; i++)
	{
		coverN = coverOne + coverTwo;
		coverOne = coverTwo;
		coverTwo = coverN;
	}
	return coverN;
}
