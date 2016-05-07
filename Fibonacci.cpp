//斐波纳挈序列数列非递归实现
long long Fibonacci(size_t n)
{
	int fib[2] = { 0,1 };
	if (n < 2)
	{
		return fib[n];
	}

	long long fibOne = 0;
	long long fibTwo = 1;
	long long fibN = 0;
	for (size_t i = 2; i <= n; i++)
	{
		fibN = fibOne + fibTwo;
		fibOne = fibTwo;
		fibTwo = fibN;
	}
	return fibN;
}

//注意事项：数据类型为long long 防止溢出，n的取值必须大于等于0
