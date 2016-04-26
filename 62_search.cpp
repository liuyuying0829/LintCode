/*
62 ������ת��������
������һ������İ�δ֪����ת����ת������(���磬0 1 2 4 5 6 7 ���ܳ�Ϊ4 5 6 7 0 1 2)������һ��Ŀ��ֵ����������������������ҵ�Ŀ��ֵ���������е�����λ�ã����򷵻�-1��

����Լ��������в������ظ���Ԫ�ء�

����
����[4, 5, 1, 2, 3]��target=1������ 2

����[4, 5, 1, 2, 3]��target=0������ -1
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
	/**
	* param A : an integer ratated sorted array
	* param target :  an integer to be searched
	* return : an integer
	*/
public:
	int search(vector<int> &A, int target) {
		// write your code here
		if (A.empty())
		{
			return -1;
		}//if

		int p = searchMin(A);
		int ret = search1(A, target, 0, p - 1);
		return ret != -1 ? ret : search1(A, target, p, A.size() - 1);
	}

	/*��ת�������в�����Сֵ*/
	int searchMin(vector<int> &A)
	{
		if (A.empty())
		{
			return -1;
		}//if

		int lhs = 0, rhs = A.size() - 1;
		if (A[lhs] <= A[rhs])
		{
			return lhs;
		}//if

		while (lhs < rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (A[mid] > A[rhs])
			{
				lhs = mid + 1;
			}//if
			else
			{
				rhs = mid;
			}//else
		}//while

		return lhs;
	}

	int search1(vector<int> &A, int target, int lhs, int rhs)
	{
		if (A.empty() || lhs > rhs)
		{
			return -1;
		}//if

		while (lhs <= rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (A[mid] == target)
			{
				return mid;
			}//if
			else if (A[mid] > target)
			{
				rhs = mid - 1;
			}//elif
			else{
				lhs = mid + 1;
			}//else
		}//while

		return -1;
	}
};
int main()
{
	vector<int> v = { 4,5,1,2,3 };
	Solution s;
	cout << s.search(v, 0) << endl;

	system("pause");
	return 0;
}