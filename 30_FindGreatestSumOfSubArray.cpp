题目描述

HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:
在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
你会不会被他忽悠住？

//连续子数组的最大和
bool g_InvalidInput = false;//是否为非法值
int FindGreatestSumOfSubArray(vector<int> array) 
{
	int size = array.size();
	//输入不合法
	if (size== 0)
	{
		g_InvalidInput = true;
		return 0;
	}
	//输入合法
	int maxSum = array[0];
	int curNum = array[0];

	for (int i = 1; i < size; i++)
	{
	  //当前的数字小于0则说明，最大的数字就是array[i]，否则就是curNum和array[i]的和
		curNum = (curNum < 0) ? array[i] : curNum + array[i];
		//最大值为当前最大值和之前的最大值得较大者
		maxSum = (maxSum > curNum) ? maxSum : curNum;
	}
	return maxSum;
}
