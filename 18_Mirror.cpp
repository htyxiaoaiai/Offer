题目描述

操作给定的二叉树，将其变换为源二叉树的镜像。 
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9  11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7   5

//二叉树的镜像
void Mirror(TreeNode *pRoot)
{
	//如果树为空或者只有一个节点直接返回，不需要交换
	if ((pRoot == NULL) || (pRoot->left == NULL && pRoot->right == NULL))
	{
		return;
	}

	//交换左右孩子
	swap(pRoot->left, pRoot->right);
	//递归交换左子树
	Mirror(pRoot->left);
	//递归交换右子树
	Mirror(pRoot->right);
}
