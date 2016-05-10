题目描述

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

class Stack
{
public:
	void push(int node) {
		//直接将数据入到stack1中
		stack1.push(node);
	}

	int pop() {

		int ret = 0;
		//如果stack2、stack1都为空则抛出异常
		if (stack2.empty() && stack1.empty())
		{
			throw exception("栈为空");
		}

		//如果stack2为空则将stack1中的元素全都放入stack2中
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}

		//stack2不为空直接出栈
		ret = stack2.top();
		stack2.pop();
		return ret;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
