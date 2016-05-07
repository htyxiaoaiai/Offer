题目描述

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

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
