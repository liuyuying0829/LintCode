/*
 40 ��ջʵ�ֶ���

�����������������Ҫʹ������ջ��ʵ�ֶ��е�һЩ������

����Ӧ֧��push(element)��pop() �� top()������pop�ǵ��������еĵ�һ��(��ǰ���)Ԫ�ء�

pop��top������Ӧ�÷��ص�һ��Ԫ�ص�ֵ��

����
����push(1), pop(), push(2), push(3), top(), pop()����Ӧ�÷���1��2��2

��ս
��ʹ������ջ��ʵ��������ʹ���κ��������ݽṹ��push��pop �� top�ĸ��Ӷȶ�Ӧ���Ǿ�̯O(1)��
*/

class Queue {
public:
	stack<int> stack1;
	stack<int> stack2;

	Queue() {
		// do intialization if necessary
	}

	void push(int element) {
		// write your code here
		stack1.push(element);
	}

	int pop() {
		// write your code here
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}//while
		}
		
		int ret = stack2.top();
		stack2.pop();
		return ret;
		
	}

	int top() {
		// write your code here
		// write your code here
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}//while
		}
		return stack2.top();
	}
};
