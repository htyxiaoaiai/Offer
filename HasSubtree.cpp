题目描述

输入两颗二叉树A，B，判断B是不是A的子结构。

二叉树的基本结构
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x)
		:val(x), left(NULL), right(NULL)
	{
	}
};


//判断是否为子结构
bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2)
{
	//proot2为空树
	if (pRoot2 == NULL)
	{
		return true;
	}
	//pRoot1为空树
	if (pRoot1 == NULL)
	{
		return false;
	}

	//都不是空树
	//根节点的值不同，主要是递归调用时判断
	if (pRoot1->val != pRoot2->val)
	{
		return false;//直接返回，不想等
	}
	//根节点相同,递归判断左右子树是否相等
	return (DoesTree1HaveTree2(pRoot1->left, pRoot2->left) && DoesTree1HaveTree2(pRoot1->right, pRoot2->right));
}

//树的子结构
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool ret = false;
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		if (pRoot1->val == pRoot2->val)
		{
			ret = DoesTree1HaveTree2(pRoot1, pRoot2);
		}
		//如果不是子结构则在左子树查找
		if (!ret)
		{
			ret = HasSubtree(pRoot1->left, pRoot2);
		}
		//如果不是子结构则在右子树查找
		if (!ret)
		{
			ret = HasSubtree(pRoot1->right, pRoot2);
		}
	}

	return ret;//返回结果
}
