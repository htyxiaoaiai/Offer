题目描述

在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2,3,1,0,2,5,3},
那么对应的输出是重复的数字2或者3。

/*
1、判断输入数组有无元素非法
2、从头扫到尾，只要当前元素值与下标不同，就做一次判断,numbers[i]与numbers[numbers[i]]，相等就认为找到了
重复元素，返回true,否则就交换两者，继续循环。直到最后还没找到认为没找到重复元素，返回false
*/

//数组中重复的数字
// Parameters:
//        numbers:     an array of integers
//        length:      the length of array numbers
//        duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false
bool duplicate(int numbers[], int length, int* duplication) {
	//参数错误
	if (length <= 0 || numbers == NULL ||
		duplication == NULL)
	{
		return false;
	}
	//判断每个数据是否在合法的范围内
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] > length - 1 || numbers[i] < 0)
		{
			return false;
		}
	}

	//判断了是否有重复数字
	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			//有重复
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}

			//不相等交换，知道交换到其下标的位置处
			swap(numbers[i], numbers[numbers[i]]);
		}
	}
	return false;
}
