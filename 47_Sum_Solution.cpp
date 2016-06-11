题目描述

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

//求1+2+3+...+n
class Temp
{
public:
	Temp()
	{
		N++;
		sum += N;
	}
	static void Reset()
	{
		N= 0;
		sum = 0;
	}
	static size_t GetSum()
	{
		return sum;
	}
private:
	static size_t N;
	static size_t sum;
};
//初始化
size_t Temp::N = 0;
size_t Temp::sum = 0;

int Sum_Solution(int n) {
	Temp::Reset();
	Temp *a = new Temp[n];
	delete[]a;
	a = NULL;
	return Temp::GetSum();
}
