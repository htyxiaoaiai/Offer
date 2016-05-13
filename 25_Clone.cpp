题目描述

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。

#include<iostream>

using namespace std;

template<class T>
struct ComplexNode
{
public:
	ComplexNode(const T& data)
		:_data(data)
		,_next(NULL)
		,_random(NULL)
	{}
public:
	T _data;//数据
	ComplexNode* _next;//指向下一个节点
	ComplexNode* _random;//指向随机节点（可以是链表中的任意节点或者空）
};

template<class T>
void CloneListNode(ComplexNode<T>* pHead)//复制链表节点并连接在该节点的后边
{
	if (pHead)//链表不为空
	{
		ComplexNode<T> * cur = pHead;
		while (cur)
		{
			ComplexNode<T>* NewNode = new ComplexNode<T>(cur->_data);
			NewNode->_next = cur->_next;
			cur->_next = NewNode;
			cur = NewNode->_next;//下一个未被复制的节点
		}
	}
}


template<class T>
void ConnectionNode(ComplexNode<T>* pHead)//更新新节点的随机指针
{
	if (pHead)//链表不为空
	{
		ComplexNode<T> * cur = pHead;
		while (cur)
		{
			ComplexNode<T> * Random = cur->_random;//随机节点

			if (Random)//随机节点可能为空
			{
				Random = cur->_random;
				cur->_next->_random = Random->_next;//将随机指针复制
			}

			cur = cur->_next->_next;//节点向后移动
		}
	}
}


template<class T>
ComplexNode<T>* ReconnectNodes(ComplexNode<T>* pHead)//将原来链表产分为两个
{
	ComplexNode<T>* newHead = NULL;
	ComplexNode<T>* first = pHead;//原来的链表
	ComplexNode<T>* second = newHead;//新的链表

	if (pHead!=NULL)//链表不为空
	{
		newHead = first->_next;
		second = newHead;
		first = first->_next;
	}

	while (first)//遍历链表
	{

		second->_next = first->_next;
		second = second->_next;

		if (second)//防止空指针的引用
		{
			first->_next = second->_next;
		}
		first = first->_next;
		
	}

	return newHead;
}


template<class T>
ComplexNode<T>*  CopyList(ComplexNode<T>* pHead)
{
	if (pHead)//链表不为空
	{
		CloneListNode(pHead);//克隆节点并且连在该节点的后边
		ConnectionNode(pHead);//连接
		ComplexNode<T>* NewHead = ReconnectNodes(pHead);//拆分
		return NewHead;
	}
	return NULL;
}


template<class T>
void CreateList(ComplexNode<T>* &pHead)//复杂链表的建立
{
	ComplexNode<T> *Node1 = new ComplexNode<T>('A');
	ComplexNode<T> *Node2 = new ComplexNode<T>('B');
	ComplexNode<T> *Node3 = new ComplexNode<T>('C');
	ComplexNode<T> *Node4 = new ComplexNode<T>('D');
	ComplexNode<T> *Node5 = new ComplexNode<T>('E');

	pHead = Node1;
	Node1->_next = Node2;
	Node2->_next = Node3;
	Node3->_next = Node4;
	Node4->_next = Node5;

	Node1->_random = Node3;
	Node2->_random = Node4;
	Node3->_random = Node5;
	Node4->_random = Node1;
	Node5->_random = Node2;

}

template<class T>

void PrintList(ComplexNode<T>* pHead)//打印复杂链表
{

	if (pHead)//链表不为空
	{
		ComplexNode<T> * cur = pHead;
		while (cur)
		{
			cout << "(" << cur->_data << " " << cur->_random->_data << ")" << "->";
			//注意随机指针可能为空，不指向任何数据，此时会导致空指针的简引用，此处为了测试效果，所以复杂链表中没有指向空指针
			cur = cur->_next;
		}
		cout<<"over" << endl;
	}
}

template<class T>
void test()
{
	ComplexNode<T>* _head;
	CreateList(_head);
	cout << "原来的链表:";
	PrintList(_head);
	cout << "复制的链表:";
	PrintList(CopyList(_head));
}

int main()
{
	test<char>();
	getchar();
	return 0;
}
