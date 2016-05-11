// 包含min函数的栈
struct Node
{
public:
	int _value;//数据
	int _min;//最小值
};
stack<Node> Stack;
void push(int value) {
	Node Data;
	Data._value = value;
	//如果栈为空或者入栈的元素小于当前栈的最小值，更新_min
	if (Stack.empty() || value < Stack.top()._min)
	{
		Data._min = value;
	}
	else
	{
		Data._min = Stack.top()._min;
	}

	Stack.push(Data);

}

void pop() {
	if (!Stack.empty())
	{
		Stack.pop();
	}

}
int top() {
	if (Stack.empty())
	{
		return -1;
	}
	return Stack.top()._value;
}
int min() {
	if (Stack.empty())
	{
		return -1;
	}
	return Stack.top()._min;
}
