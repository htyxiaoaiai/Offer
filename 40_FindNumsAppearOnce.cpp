题目描述

一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
  //数组中只出现一次的数字
void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
{
	if (data.size() < 2)
	{
		return;
	}
	int myxor = 0;
	int flag = 1;
	//每个数字异或
	for (size_t i = 0; i < data.size(); i++)
	{
		myxor ^= data[i];
	}

//找到两个不同数中，最低一位为1的位
	while ((flag&myxor) == 0)
	{
		flag <<= 1;
	}
	*num1 = myxor;
	*num2 = myxor;
	//将所有数字分成两组
	for (size_t i = 0; i < data.size(); i++)
	{
	 //与不同的那个数字第一个为1的位不同的数字
		if ((data[i] & flag) == 0)
		{
			*num1 ^= data[i];
		}
		//与不同的那个数字第一个为1的位相同的数字
		else
		{
			*num2 ^= data[i];
		}
	}
}
