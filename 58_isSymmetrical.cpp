题目描述

请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的

/递归
//对称的二叉树
bool _isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL&&pRoot2 == NULL)
		return true;

	if (pRoot1 == NULL && pRoot2 != NULL)
		return false;
	if (pRoot2 == NULL&&pRoot1 != NULL)
		return false;

	if (pRoot1->val == pRoot2->val)
		return _isSymmetrical(pRoot1->left, pRoot2->right) && _isSymmetrical(pRoot1->right, pRoot2->left);

    return false;
	
	
}
bool isSymmetrical(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return true;

	return _isSymmetrical(pRoot, pRoot);
}


//非递归
bool isSymmetrical(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return true;
	queue<TreeNode*> q1;
	queue<TreeNode*> q2;

	TreeNode* left, *right;
	q1.push(pRoot->left);
	q2.push(pRoot->right);
	while (!q1.empty()&&q2.empty())
	{
		left = q1.front();
		q1.pop();
		right = q2.front();
		q2.pop();
		
		if (left == NULL&&right == NULL)
			continue;

		if (left == NULL || right == NULL)
			return false;

		if (left->val != right->val)
			return false;

		q1.push(left->left);
		q1.push(left->right);
		q2.push(right->right);
		q2.push(right->left);
	}
	return true;

}
