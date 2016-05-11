题目描述

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。

//栈的压入弹出序列
bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	stack<int> s;//辅助栈
	//当两个顺序标的大小相等，并且Size大于0
	if (pushV.size() == popV.size() && pushV.size() > 0)
	{
		size_t in = 0;//入栈序列的下标
		size_t out = 0;//出栈序列的下标
	
		//用出栈序列的大小限制循环
		while (out < popV.size())
		{
			while (s.empty() || s.top() != popV[out])
			{
				if (in == pushV.size())
				{
					break;//pushV遍历完跳出
				}
				s.push(pushV[in++]);
			}

			////pushV遍历完跳出，判断最后一个元素是否相等，不等则直接返回false;
			if (s.top() != popV[out])
			{
				return false;
			}

			s.pop();
			out++;
		}

		return true;//出栈序列遍历完成跳出循环，则返回true
	}
	else
	{
		return false;
	}
}

void TestIsPopOrder()
{
	vector<int> pushV = { 1,2,3,4,5 };
	vector<int> popV = { 4,3,5,2,2 };
	cout<<IsPopOrder(pushV,popV)<<endl;
}
