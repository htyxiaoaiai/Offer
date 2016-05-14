题目描述

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

解题思路：
采用阵地攻守的思想： 
第一个数字作为第一个士兵，守阵地；count = 1； 遇到相同元素，count++; 遇到不相同元素，即为敌人，同归于尽,count--；
当遇到count为0的情况，又以新的i值作为守阵地的士兵，继续下去，到最后还留在阵地上的士兵，有可能是主元素，也有可能是最后一个元素。
再加一次循环，记录这个士兵的个数看是否大于数组一般即可。

//数组中出现次数超过一半的数字
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	int size = numbers.size();
	//数组异常
	if (size <= 0)
	{
		return 0;
	}

	//计数器置为1，并将初始数字设为数组的第一个元素
	int count = 1;
	int num = numbers[0];

	//遍历数组
	for (int i = 1; i < size; i++)
	{
		//相等计数器+1
		if (num == numbers[i])
		{
			count++;
		}
		else
		{
			//不想等计数器-1
			--count;
			//计数器为0，,重新初始化
			if (count == 0)
			{
				num = numbers[++i];
				count = 1;
			}
		}
	}
	
	//数组遍历完成之后，确定是否超过了一半，可能是最后一个元素
	count = 0;
	for (int i = 0; i < size; i++)
	{
		if (num == numbers[i])
		{
			count++;
		}
	}

	if (count * 2 > size)
	{
		return num;
	}
	return 0;
}
