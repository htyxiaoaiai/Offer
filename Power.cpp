题目描述

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

//求double类型的整数次方
double Power(double base, int exponent) 
{
	//指数为0
	if (exponent == 0)
	{
		return 1;
	}
	//指数小于0
	if (exponent < 0)
	{
		return 1/Power(base, -exponent);
	}

	//大于0，先算偶数次幂
	double ret = Power(base*base, exponent / 2);
	//奇次幂
	if (exponent % 2 == 1)
	{
		ret = base*ret;
	}
	return ret;
}

//测试函数
void TestPower()
{
	cout << Power(2.0, -4) << endl;
}
