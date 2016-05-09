题目描述

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

//非递归实现
//合并两个有序的单链表
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	//新链表的头
	ListNode* newHead = NULL;
	//两个链表均为空链表
	if (NULL == pHead1 && NULL == pHead2)
	{
		return NULL;
	}

	//其中一个链表为空
	if (NULL == pHead1 && pHead2 != NULL)
	{
		return pHead2;
	}

	if (pHead1 != NULL && NULL == pHead2)
	{
		return pHead1;
	}

	//两个链表均不为空
	//找到头节点
	if (pHead1->val < pHead2->val)
	{
		newHead = pHead1;
		pHead1 = pHead1->next;
	}
	else
	{
		newHead = pHead2;
		pHead2 = pHead2->next;
	}

	ListNode* cur = newHead;
	while (pHead1 && pHead2)
	{
		if (pHead1->val < pHead2->val)
		{
			cur->next = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			cur->next = pHead2;
			pHead2 = pHead2->next;
		}
		cur = cur->next;
	}

	//pHead1不为空，pHead2为空
	if (pHead1)
	{
		cur->next = pHead1;
	}
	else
	{
		cur->next = pHead2;
	}

	return newHead;
}

//递归实现
//合并两个有序的单链表
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	//新链表的头
	ListNode* newHead = NULL;
	//两个链表均为空链表
	if (NULL == pHead1 && NULL == pHead2)
	{
		return NULL;
	}

	//其中一个链表为空
	if (NULL == pHead1 && pHead2 != NULL)
	{
		return pHead2;
	}

	if (pHead1 != NULL && NULL == pHead2)
	{
		return pHead1;
	}

	//两个链表均不为空
	//找到头节点
	if (pHead1->val < pHead2->val)
	{
		newHead = pHead1;
		newHead->next = Merge(pHead1->next, pHead2);
	}
	else
	{
		newHead = pHead2;
		newHead->next = Merge(pHead1, pHead2->next);
	}
	return newHead;
}
