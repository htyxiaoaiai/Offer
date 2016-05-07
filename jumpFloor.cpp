题目描述

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

解法分析：
最简单的情况：
如果只有1级台阶，那么显然只有一种跳法。如果有2级台阶，那么则会有2种跳法：一种是分两次跳，每次跳1阶；另外一种则是一次跳2级。

一般情况：
当n大于2时，第一次跳的时候有两种选择：一种是第一次只跳1阶，此时的跳法就是f(n-1),另外一种跳法就是第一次跳2阶，然后此时的跳法就是f(n-2)。
所以总的次数就是f(n)=f(n-1)+f(n-2);很明显此时是一个斐波那契数列。

//跳台阶
long long jumpFloor(size_t number) {
	size_t jump[2] = { 0,1 };
	if (number < 2)
	{
		return jump[number];
	}

	long long jumpOne = 1;
	long long jumpTwo = 1;
	long long jumpN = 0;
	for (size_t i = 2; i <= number; i++)
	{
		jumpN = jumpOne + jumpTwo;
		jumpOne = jumpTwo;
		jumpTwo = jumpN;
	}
	return jumpN;
}
