题目描述

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

//二叉搜索树的后序遍历序列
//递归解法
bool VerifySquenceOfBST(vector<int> sequence)
{
	size_t size = sequence.size();
	//数组中必须含有节点
	if (size < 1)
	{
		return false;
	}
	int root = sequence[size - 1];
	//存储左右孩子的数组
	vector<int> left, right;
	//左孩子的数字比根节点小
	size_t i = 0;
	for (; i < size - 1; i++)
	{
		if (sequence[i]>root)
		{
			break;
		}
		left.push_back(sequence[i]);
	}
	//右子树的孩子比根节点大
	int j = i;
	for (; j < size - 1; j++)
	{
		if (sequence[j] < root)
		{
			return false;
		}
		right.push_back(sequence[j]);
	}

	//左子树是否为后序线索化二叉树
	bool leftS = true;
	if (left.size()>0)
	{
		leftS = VerifySquenceOfBST(left);
	}
	//右子树是否为后序线索化二叉树
	bool rightS = true;
	if (right.size()>0)
	{
		rightS = VerifySquenceOfBST(right);
	}

	return (leftS&&rightS);
}


//非递归 
//非递归也是一个基于递归的思想：
//左子树一定比右子树小，因此去掉根后，数字分为left，right两部分，right部分的
//最后一个数字是右子树的根他也比左子树所有值大，因此我们可以每次只看有子树是否符合条件
//即可，即使到达了左子树左子树也可以看出由左右子树组成的树还想右子树那样处理

//对于左子树回到了原问题，对于右子树，左子树的所有值都比右子树的根小可以暂时把他看出右子树的左子树
//只需看看右子树的右子树是否符合要求即可

//二叉搜索树的后序遍历序列
bool VerifySquenceOfBST(vector<int> sequence)
{
		size_t size = sequence.size();
		//数组中必须含有节点
		if (size < 1)
		{
			return false;
		}

		int i = 0;
		while (--size)
		{
			//左子树都比根节点小
			while (sequence[i++] < sequence[size]);
			//右子树都比根节点大
			while (sequence[i++] > sequence[size]);

			//期间有节点不满足，例如7,4,6,5
			if (i < size)
			{
				return false;
			}

			i = 0;
		}

		return true;
}
