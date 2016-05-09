题目描述

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

/*特殊情况
1、对0求倒数
2、base为0，指数是负数
3、指数为负数
4、0的0次方，输出1还是0
*/

方法一：
//判断浮点数是否相等
bool equal(double num1, double num2)
{
	if (num1 - num2 > -0.0000001&&num1 - num2 < 0.000001)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//计算double类型的正整数次方
double PowerWithUnsigned(double base, unsigned int absExponment)
{
	double result = 0.0;
	for (size_t i = 1; i <= absExponment; i++)
	{
		result *= base;
	}
	return result;
}

bool g_InavildInput = false;//全局变量，判断是否是非法输入
double Power(double base, int exponent) 
{
	g_InavildInput = false;
	if (equal(base, 0.0) && exponent < 0)
	{
		g_InavildInput = true;//非法输入
		return 0.0;
	}

	//给exponment求绝对值
	unsigned int absExponment = (unsigned int)exponent;
	if (exponent < 0)
	{
		absExponment= (unsigned int)(-exponent);
	}

	double result = PowerWithUnsigned(base, absExponment);
	if (exponent < 0)
	{
		result = 1.0 / result;//求倒数
	}
	return result;
}

方法二：更快捷高效
//求double类型的整数次方
double Power(double base, int exponent) 
{
	if (equal(0.0, base) && exponent < 0)
	{
		throw new exception("输入非法");
	}
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
