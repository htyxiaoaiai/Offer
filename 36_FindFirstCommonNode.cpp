题目描述

输入两个链表，找出它们的第一个公共结点。

//查找两个链表的第一个公共节点
//求链表的长度
size_t  GetListLength(ListNode* pHead)
{
	ListNode* cur = pHead;
	size_t length = 0;
	while (cur)
	{
		length++;
		cur = cur->next;
	}
	return length;
}

ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
	size_t leftLen = GetListLength(pHead1);
	size_t rightLen = GetListLength(pHead2);
	int diffLen = leftLen - rightLen;
	ListNode* ListLong = pHead1;
	ListNode* ListShort = pHead2;

	//求两个链表的长度之差
	if (diffLen < 0)
	{
		ListLong = pHead2;
		ListShort = pHead1;
		diffLen = -diffLen;
	}

	//长链表先走diff步
	while (diffLen--)
	{
		ListLong = ListLong->next;
	}

	//两个链表同时走
	while (ListLong)
	{
		if (ListLong == ListShort)
		{
			return ListLong;
		}
		ListLong = ListLong->next;
		ListShort = ListShort->next;
	}
	return NULL;
}
