//顺时针打印矩阵的一圈
void PrintOneCircle(vector<vector<int>>& matrix, vector<int>& ret, int  start)
{
	int  rowSize = matrix.size();//行数
	int  colSize = matrix[0].size();//列数

	int  endX = colSize - start - 1;//列结束的位置
	int  endY = rowSize - start - 1;//行结束的位置

	//从左到右打印一行
	for (int i = start; i <= endX; i++)
	{
		ret.push_back(matrix[start][i]);
	}
	//从上到下打印一列
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; i++)
		{
			ret.push_back(matrix[i][endX]);
		}
	}
	//从右到左打印一行
	if ((start < endY) && (endX > start))
	{
		for (int i = endX - 1; i >= start; i--)
		{
			ret.push_back(matrix[endY][i]);
		}
	}
	//从下到上打印一列
	if ((start < endY - 1) && (endX > start))
	{
		for (int i = endY - 1; i > start; i--)
		{
			ret.push_back(matrix[i][start]);
		}
	}
}

//顺时针打印矩阵
vector<int> printMatrix(vector<vector<int>> matrix)
{
	vector<int> ret;//存放打印的结果
	if (matrix.size() < 1)
	{
		return ret;//如果矩阵的元素个数小于1,直接返回
	}
	int rowSize = matrix.size();//行数
	int colSize = matrix[0].size();//列数
	int start = 0;//开始打印的下标
	//逐圈的打印
	while (rowSize > start * 2 && colSize > start * 2)
	{
		PrintOneCircle(matrix, ret, start);
		start++;
	}

	return ret;
}

//测试函数
void TestPrintMatrix()
{
	vector<vector<int>> matrix = { {1,2,3},{5,6,7},{9,10,11},{13,14,15} };
	vector<int> ret;
	ret = printMatrix(matrix);
	int i = 0;
	while (i < ret.size())
	{
		cout << ret[i++] << " ";
	}
	cout << endl;
}

