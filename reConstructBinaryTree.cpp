题目描述

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回

思路分析
/* 先序遍历第一个位置肯定是根节点root，

中序遍历的根节点位置在中间pos，在pos左边的肯定是root的左子树的中序数组，pos右边的肯定是root的右子树的中序数组

另一方面，先序遍历的第二个位置到pos，也是node左子树的先序子数组，剩下pos右边的就是root的右子树的先序子数组

把四个数组找出来，分左右递归调用即可

*/
//二叉树的节点结构
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//重建二叉树
struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
	//当左右子树的顺序表为空时返回递归
	size_t size = in.size();
	if (size == 0)
	{
		return NULL;
	}

	//在前序序列中第一个节点根节点
	TreeNode* root = new TreeNode(pre[0]);

	//在中序序列中找到根节点
	size_t pos = 0;//根节点在中序序列中的位置
	for (pos = 0; pos < size; pos++)
	{
		if (in[pos] == pre[0])
		{
			break;
		}
	}

	vector<int> pre_left, pre_right, in_left, in_right;

	//构建先序遍历序列
	for (size_t i = 1; i < size; i++)
	{
		if (i <= pos)
		{
			pre_left.push_back(pre[i]);
		}
		if (i > pos)
		{
			pre_right.push_back(pre[i]);
		}
	}
	//构建左右两个中序遍历序列
	for (size_t i = 0; i < size; i++)
	{
		if (i < pos)
		{
			in_left.push_back(in[i]);
		}

		if (i > pos)
		{
			in_right.push_back(in[i]);
		}
	}

	//递归重建左子树
	root->left = reConstructBinaryTree(pre_left, in_left);
	//递归重建右子树
	root->right = reConstructBinaryTree(pre_right, in_right);
	return root;
}

void TestreConstructBinaryTree()
{
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> in = { 4,7,2,1,5,3,8,6 };
	TreeNode* root=reConstructBinaryTree(pre, in);

}
