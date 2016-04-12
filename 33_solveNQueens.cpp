/*
33 N�ʺ�����

n�ʺ������ǽ�n���ʺ������n*n�������ϣ��ʺ�˴�֮�䲻���໥������

����һ������n���������в�ͬ��n�ʺ�����Ľ��������
ÿ�������������һ����ȷ��n�ʺ���ò��֣����С�Q���͡�.���ֱ��ʾһ��Ů����һ����λ�á�
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
	* Get all distinct N-Queen solutions
	* @param n: The number of queens
	* @return: All distinct solutions
	* For example, A string '...Q' shows a queen on forth position
	*/
	/*����һ���ݹ�ʵ��*/
	vector<vector<string> > solveNQueens1(int n) {
		// write your code here
		vector<vector<string>> solutions;
		/*��һά����洢*/
		vector<int> queue(n, -1);
		/*��һά����洢*/
		recursiveFun(solutions, queue, n, 0);
		return solutions;
	}

	/*�ݹ�ʵ��*/
	void recursiveFun(vector<vector<string>> &solutions, vector<int> &queue, int n, int row)
	{
		if (row >= n)
		{
			vector<string> ret = getResult(queue);
			solutions.push_back(ret);
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
	vector<vector<string> > solveNQueens(int n) {
		// write your code here
		vector<vector<string>> solutions;
		/*��һά����洢*/
		vector<int> queue(n, -1);
		int i = 0, j = 0;
		while(i < n)
		{
			while(j < n)
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
				vector<string> ret = getResult(queue);
				solutions.push_back(ret);

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

	/*������Ҫ��Ľ�����ַ��������ʾ*/
	vector<string> getResult(vector<int> queue)
	{
		if (queue.empty())
		{
			return vector<string>();
		}

		int len = queue.size();
		vector<string> ret(len, string(len,'.'));
		for (int i = 0; i < len; ++i)
		{
			ret[i][queue[i]] = 'Q';
		}//for
		return ret;
	}
};

int main()
{
	Solution s;
	vector<vector<string>> ret = s.solveNQueens1(4);

	for (auto iter1 = ret.begin(); iter1 != ret.end(); ++iter1)
	{
		for (auto iter2 = (*iter1).begin(); iter2 != (*iter1).end(); ++iter2)
		{
			cout << *iter2 << endl;
		}//for
	}//for

	system("pause");
	return 0;
}