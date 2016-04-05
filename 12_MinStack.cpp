/*
 12 ����Сֵ������ջ

ʵ��һ������ȡ��Сֵmin������ջ��min���������ص�ǰջ�е���Сֵ��

��ʵ�ֵ�ջ��֧��push��pop �� min ���������в���Ҫ����O(1)ʱ������ɡ�
*/

class MinStack {
public:
	MinStack() {
		// do initialization if necessary
	}

	void push(int number) {
		// write your code here
		datas.push(number);
		if (minDatas.empty())
		{
			minDatas.push(number);
		}
		else{
			if (number < minDatas.top())
			{
				minDatas.push(number);
			}
			else{
				minDatas.push(minDatas.top());
			}//else
		}//else
	}

	int pop() {
		// write your code here
		int ret = datas.top();
		datas.pop();
		minDatas.pop();
		return ret;
	}

	int min() {
		// write your code here
		return minDatas.top();
	}

private:
	stack<int> datas;
	stack<int> minDatas;
};
