
题目描述

LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,
并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。
LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。
为了方便起见,你可以认为大小王是0。


bool IsContinuous(vector<int> numbers)
{
	size_t size = numbers.size();
	//抽的扑克牌的数量不是5
	if (size != 5)
	{
		return false;
	}
	//排序
	sort(numbers.begin(), numbers.end());
	//超出了扑克牌的表示范围
	if (numbers[size - 1] > 13)
	{
		return false;
	}

	//统计数组中0的个数（大小王）
	size_t numOfZero = 0;
	for (size_t i = 0; i < size && numbers[i] == 0; i++)
	{
		numOfZero++;
	}

	//王的个数为4
	if (numOfZero > 4)
	{
		return false;
	}

	//统计数组中的间隔数
	size_t small = numOfZero;//非0值的下标
	size_t big = small + 1;
	size_t numOfGap = 0;
	while (big < size)
	{
		//对子
		if (numbers[small] == numbers[big])
		{
			return false;
		}

		//非对子
		numOfGap += numbers[big] - numbers[small] - 1;
		small = big++;
	}

	return (numOfZero >= numOfGap) ? true : false;

}
