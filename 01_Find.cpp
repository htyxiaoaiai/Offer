题目描述

在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。 
输入描述:
array： 待查找的二维数组
target：查找的数字


输出描述:
查找到返回true，查找不到返回false

//二维数组的查找
bool Find(vector<vector<int> > array, int target) {
	int row = array.size();//获取行数
	int col = array[0].size();//获取列数

	//从左上角开始寻找
	int rows = 0;
	int cols = col - 1;
	while (rows < row && cols >= 0)
	{
		//该数字比左上角的元素小，则排除一整列
		if (array[rows][cols] > target)
		{
			cols--;
		}
		//该数字比左上角的元素大，则排除一行
		else if (array[rows][cols] < target)
		{
			rows++;
		}
		else
		{
			return true;//找到
		}
	}

	return false;//没有找到
}

void TestFind()
{
	vector<vector<int> > array = { {1,2,8,9},{2,4,9,12} ,{4,7,10,13},{6,8,11,15} };
	cout << Find(array, 9) << endl;
	cout << Find(array, 15) << endl;
	cout << Find(array, 1) << endl;
	cout << Find(array, 6) << endl;
	cout << Find(array, 7) << endl; 
	cout << Find(array, 4) << endl;
	cout << Find(array, 11) << endl;
	cout << Find(array, 0) << endl;
}
