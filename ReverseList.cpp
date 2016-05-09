题目描述

输入一个链表，反转链表后，输出链表的所有元素。

//反转链表
ListNode* ReverseList(ListNode* pHead)
{
	ListNode *cur = pHead;//当前节点
	ListNode *NewHead = NULL;//新的头结点
	ListNode *prev = NULL;//前驱指针

	while (cur)
	{
		prev = cur;
		cur = cur->next;
		prev->next = NewHead;
		NewHead = prev;
	}
	return NewHead;
}
