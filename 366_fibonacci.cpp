/*
366 쳲���������

����쳲����������е� N ������

��ν��쳲�����������ָ��

ǰ2������ 0 �� 1 ��
�� i �����ǵ� i-1 �����͵�i-2 �����ĺ͡�
쳲��������е�ǰ10�������ǣ�

0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...

������ʵ���������Ƿ�����������⣿ Yes
����
���� 1������ 0

���� 2������ 1

���� 10������ 34
*/
class Solution {
public:
	/**
	* @param n: an integer
	* @return an integer f(n)
	*/
	int fibonacci(int n) {
		// write your code here
		if (n == 1)
		{
			return 0;
		}
		else if (n == 2)
		{
			return 1;
		}
		else {
			long long lastOne = 1;
			long long lastTwo = 0;

			long long retN = 0;
			for (int i = 3; i <= n; ++i)
			{
				retN = lastOne + lastTwo;

				lastTwo = lastOne;
				lastOne = retN;
			}
			return retN;
		}
	}

	int fibonacci1(int n)
	{
		if (n == 1)
		{
			return 0;
		}
		else if (n == 2)
		{
			return 1;
		}
		else {
			return fibonacci1(n - 1) + fibonacci1(n - 2);
		}
	}

	int fibonacci2(int n)
	{
		if (n == 1)
		{
			return 0;
		}
		else if (n == 2)
		{
			return 1;
		}
		else {
			vector<int> ret(n + 1,0);
			ret[1] = 0;
			ret[2] = 1;
			for (int i = 3; i <= n; ++i)
			{
				ret[i] = ret[i - 1] + ret[i - 2];
			}//for
			return ret[n];
		}
	}
};