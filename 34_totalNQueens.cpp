/*
34 N�ʺ����� II

����n�ʺ����⣬���ڷ���n�ʺ�ͬ�Ľ�����������������Ǿ���ķ��ò��֡�
����
����n=4������2�ֽ������
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* Calculate the total number of distinct N-Queen solutions.
	* @param n: The number of queens.
	* @return: The total number of distinct solutions.
	*/
	int totalNQueens1(int n) {
		// write your code here
		int solutions = 0;
		/*��һά����洢*/
		vector<int> queue(n, -1);
		/*��һά����洢*/
		recursiveFun(solutions, queue, n, 0);
		return solutions;
	}

	/*�ݹ�ʵ��*/
	void recursiveFun(int &solutions, vector<int> &queue, int n, int row)
	{
		if (row >= n)
		{
			++solutions;
		}//if
		else{
			for (int j = 0; j < n; ++j)
			{
				/*�ݹ�����һ������ɹ���*/
				if (isValid(queue, row, j))
				{
					queue[row] = j;
					recursiveFun(solutions, queue, n, row + 1);
				}//if
			}//else
		}//else
	}

	/*���������ǵݹ�ʵ��*/
	int totalNQueens(int n) {
		// write your code here
		int solutions = 0;
		/*��һά����洢*/
		vector<int> queue(n, -1);
		int i = 0, j = 0;
		while (i < n)
		{
			while (j < n)
			{
				if (isValid(queue, i, j))
				{
					/*��i�еĻʺ����Ϊj*/
					queue[i] = j;

					/*����̽����һ���ʺ��λ��*/
					j = 0;
					break;
				}//if
				else{
					++j;
				}//else
			}//while

			/*��i��û���ҵ����Է��ûʺ��λ�ã�˵���÷���������*/
			if (-1 == queue[i])
			{
				/*��ǰû�п��н���б�Ϊ0��˵���Ѿ��������еĽ�*/
				if (0 == i)
				{
					break;
				}//if
				/*���ݵ���һ��*/
				else
				{
					--i;
					/*�ı���һ�лʺ��λ��*/
					j = queue[i] + 1;
					queue[i] = -1;
					continue;
				}//else
			}//if

			/*�ҵ�һ�����н�*/
			if (i == n - 1)
			{
				++solutions;

				/*�����ڴ˴�����������Ϊ����Ҫ�ҵ���N�ʺ���������н⣬��ʱӦ��������еĻʺ�
				�ӵ�ǰ���ûʺ���������һ�м���̽�⡣*/
				j = queue[i] + 1;
				queue[i] = -1;
				continue;
			}//if
			++i;
		}//while
		return solutions;
	}


	/*�ж���r��c�з��ûʺ��Ƿ�Ϸ�*/
	bool isValid(vector<int> queue, int r, int c)
	{
		if (queue.empty())
			return true;
		for (int i = 0; i < r; ++i)
		{
			if (queue[i] == c || abs(i - r) == abs(queue[i] - c))
				return false;
		}//for
		return true;
	}
};


int main()
{
	Solution s;
	cout << s.totalNQueens1(4) << endl;

	

	system("pause");
	return 0;
}