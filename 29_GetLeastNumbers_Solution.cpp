题目描述

输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

思路
采取堆排序，建立大小为K的大根堆
如果剩余的n-k个数中有小于大根堆的根节点的话，则直接更新根节点并再次调整为大根堆

//向下调整
void AdjustDown(vector<int>& input, int parent)
{
	int size = input.size();
	int child = parent * 2 + 1;
	while (child < size)
	{
		//找到左右孩子中较大的节点
		if (child + 1 < size && input[child + 1] > input[child])
		{
			child++;
		}

		//找到较大的节点
		if (input[child]>input[parent])
		{
			swap(input[child], input[parent]);
			//继续调整
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//最小的K个数
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	//输入的参数错误
	int size = input.size();
	vector<int> BigHeap;
	if (k > 0 && k <= size)
	{
		//构建堆大小为k的大根堆

		for (int i = 0; i < k; i++)
		{
			BigHeap.push_back(input[i]);
		}

		for (int i = (size - 2) / 2; i >= 0; i--)
		{
			AdjustDown(BigHeap, i);
		}

		//剩余的size-K个节点中，如果比根节点小，则直接将根节点替换，并再次调整
		for (int i = k; i < size; i++)
		{
			if (input[i] < BigHeap[0])
			{
				BigHeap[0] = input[i];
				AdjustDown(BigHeap, 0);
			}
		}
	}
	return BigHeap;
}

//测试函数
void TestGetLeastNumbers_Solution()
{
	vector<int> array = { 4,5,1,6,2,7,3,8 };
	vector<int> ret = GetLeastNumbers_Solution(array, 4);

}
