题目描述

输入一个链表，从尾到头打印链表每个节点的值。 
输入描述:
输入为链表的表头


输出描述:
输出为需要打印的“新链表”的表头

//链表结构
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

vector<int> printListFromTailToHead(struct ListNode* head) {
	ListNode* cur = head;
	std::stack<int> nodes;
	//通过栈来实现
	while (cur)
	{
		nodes.push(cur->val);
		cur = cur->next;
	}
	vector<int> ans;
	while (!nodes.empty())
	{
		ans.push_back(nodes.top());
		nodes.pop();
	}
	return ans;//返回顺序表
}

//注意最好入栈的时候将指针入栈，如果链表的数据类型为复杂类型则会比较浪费空间
