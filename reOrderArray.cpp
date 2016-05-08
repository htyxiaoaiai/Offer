题目描述

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

//调整数组使奇数全都位于前方，且相对位置不变
//类似于冒泡排序，当前边一个数是奇数，后边一个数是偶数交换
void reOrderArray(vector<int> &array) 
{
	//个数小于等于1
	if (array.size() <= 1)
	{
		return;
	}

	size_t size = array.size();
	for (size_t i = 1; i < size; i++)//冒泡的次数
	{
		for (size_t j = 0; j < size - i; j++)//冒泡
		{
			if (array[j] % 2 == 0 && array[j + 1] % 2 == 1)
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
}
//算法复杂度为O(N^2)

//创建两个数组
void reOrderArray(vector<int> &array)
{
	size_t size = array.size();
	//数组个数小于等于1
	if (size <= 1)
	{
		return;
	}

	vector<int> even;//存放偶数
	vector<int> odd;//存放奇数
	for (size_t i = 0; i < size; i++)
	{
		//奇数
		if (array[i] % 2 == 1)
		{
			odd.push_back(array[i]);
		}
		//偶数
		else
		{
			even.push_back(array[i]);
		}
	}

	//奇数拷贝
	size_t i = 0;
	for (; i < odd.size();i++)
	{
		array[i] = odd[i];
	}

	//偶数拷贝
	for (size_t j = 0; j < even.size(); j++)
	{
		array[i++] = even[j];
	}
}

//算法复杂度为O(N)

//测试函数
void TestReOrderArray()
{
	vector<int> a = { 1,2,3,4,5,6 ,11 };
	reOrderArray(a);
	for (size_t i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
