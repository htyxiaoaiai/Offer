题目描述

输入一棵二叉树，判断该二叉树是否是平衡二叉树。

//判断是不是平衡二叉树
//使用后序遍历算法，在遍历节点的时候，左子树右子树已经遍历，保存深度并判断根节点是不是平衡二叉树
bool IsBalanced(TreeNode* pRoot, int & depth)
{
	if (pRoot == NULL)
	{
		depth = 0;
		return true;
	}
	int left = 0;
	int right = 0;
	//左右子树都为平衡二叉树
	if (IsBalanced(pRoot->left, left) &&
		IsBalanced(pRoot->right, right))
	{
		int diff = left - right;
		if (diff >= -1 && diff <= 1)
		{
			//计算深度
			depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}
bool IsBalanced_Solution(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return true;
	int depth = 0;
	return IsBalanced(pRoot, depth);
}
