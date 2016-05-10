题目描述

输入一个链表，输出该链表中倒数第k个结点。

//链表结构
struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL)
	{}
};

//输出倒数第k个节点
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	//输入不合法
	if (pListHead == NULL || k == 0)
	{
		return NULL;
	}

	ListNode* pAhead = pListHead;
	ListNode* pBehind = NULL;

	//先移动k步
	for (size_t i = 0; i < k; i++)
	{
		//节点长度多于k
		if (pAhead)
		{
			pAhead = pAhead->next;
		}
		else
		//节点长度小于k，直接返回
		{
			return NULL;
		}
	}

	//继续遍历到最后
	pBehind = pListHead;
	while (pAhead)
	{
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pBehind;//找到
}
