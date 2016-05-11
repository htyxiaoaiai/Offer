题目描述

从上往下打印出二叉树的每个节点，同层节点从左至右打印。

//从上到下打印二叉树
vector<int> PrintFromTopToBottom(TreeNode *root) 
{
	queue<TreeNode*> q;//队列
	vector<int> ret;//存储结果

	if (root != NULL)
	{
		q.push(root);//根节点入队
		while (!q.empty())
		{
			//队头的左孩子不为空，入队
			if (q.front()->left)
			{
				q.push(q.front()->left);
			}
			//队头的右孩子不为空，入队
			if (q.front()->right)
			{
				q.push(q.front()->right);
			}
			//将队头出队
			ret.push_back(q.front()->val);
			q.pop();
		}
	}
	return ret;
}

