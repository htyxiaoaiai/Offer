题目描述

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

//递归将二叉树排序
void _Convert(TreeNode* pRootOfTree, TreeNode* & pLastNode)
{
	if (pRootOfTree == NULL)
	{
		return;
	}

	TreeNode* curNode = pRootOfTree;
	//递归排序左子树
	if (curNode->left != NULL)
	{
		_Convert(curNode->left, pLastNode);
	}

	//修改前驱
	curNode->left = pLastNode;
	//修改后继
	if (pLastNode != NULL)
	{
		pLastNode->right = curNode;
	}

	//更新pLastNode
	pLastNode = curNode;

	//递归排序右子树
	if (curNode->right != NULL)
	{
		_Convert(curNode->right, pLastNode);
	}
}

//二叉搜索树转换为排序的双向链表
TreeNode* Convert(TreeNode* pRootOfTree)
{
	//二叉树为空
	if (pRootOfTree == NULL)
	{
		return NULL;
	}
	//双向链表的最后一个节点
	TreeNode* pLastNode = NULL;
	_Convert(pRootOfTree, pLastNode);

	//由于是最后一个节点，遍历找到头结点。向前遍历，左子树保存的是前驱节点
	TreeNode* newHead = pLastNode;
	while (newHead != NULL&&newHead->left != NULL)
	{
		newHead = newHead->left;
	}
	return newHead;//返回头节点
}
