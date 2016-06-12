题目描述

将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。

//把字符串转换成整数
enum Statue
{
	g_valid,//合法的
	g_invalid//非法的
};
Statue stats = g_valid;
//将合法的字符转换为整型
long long _StrToInt(char* Cstr, char Csymbol)
{
	long long sum = 0;
	while (*Cstr >= '0'&&*Cstr <= '9')
	{
		sum *= 10;
		sum += *Cstr - '0';
		//判断是否溢出
		if ((Csymbol < 0 && sum > 0x80000000) || (Csymbol>0 && sum>0x7FFFFFFF))
		{
			//非法
			stats = g_invalid;
			return 0;
		}
		Cstr++;
	}
	if (*Cstr != '\0')
	{
		//非法
		stats = g_invalid;
		return 0;
	}
	return sum*Csymbol;
}
int StrToInt(string str) {

	if (!str.empty())
	{
		char* Cstr = (char*)str.c_str();
		//跳过空格
		while (*Cstr == ' ')
		{
			Cstr++;
		}
		//读取符号位
		char Csymbol = 1;
		if (*Cstr == '+')
		{
			Cstr++;
		}
		else if (*Cstr == '-')
		{
			Csymbol = -1;
			Cstr++;
		}

		//如果是合法的字符则进行转换
		if (*Cstr >= '0'&&*Cstr <= '9')
		{
			return (int)_StrToInt(Cstr, Csymbol);
		}
	}
	//非法
	stats = g_invalid;
	return 0;
}
