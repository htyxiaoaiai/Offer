
题目描述

输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。//二叉树中和为某一值的路径

//注意Path和tmp使用引用
void _FindPath(TreeNode* root, int left, vector<vector<int>> &Path, vector<int>& tmp)
{
	tmp.push_back(root->val);
	//路径之和相等，并且为叶子节点
	if (left - root->val == 0 && (root->left == NULL&&root->right == NULL))
	{
		Path.push_back(tmp);
	}
	else
	{
		//前序遍历左子树
		if (root->left)
		{
			_FindPath(root->left, left-root->val, Path, tmp);
		}
		//前序遍历右子树
		if (root->right)
		{
			_FindPath(root->right, left - root->val, Path, tmp);
		}
	}
	//如果找到一条路径，则将最后一个节点删除，重新寻找，
	//如果是找到了叶子节点仍然没有找到，跳出上层节点，并将该结点删除
	tmp.pop_back();
}

vector<vector<int>> FindPath(TreeNode* root, int expectNumber)
{
	vector<vector<int>> Path;//保存所有路径
	vector<int> tmp;//保存单条路径
	if (root != NULL)
	{
		_FindPath(root, expectNumber, Path, tmp);
	}
	return Path;
}
