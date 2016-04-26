/*
63 ������ת�������� II

������������ת�������顱���������ظ�Ԫ���ֽ���Σ�

�Ƿ��Ӱ������ʱ�临�Ӷȣ�

���Ӱ�죿

Ϊ�λ�Ӱ�죿

д��һ�������жϸ�����Ŀ��ֵ�Ƿ�����������С�

����
����[3,4,4,5,7,0,1,2]��target=4������ true
*/

class Solution {
	/**
	* param A : an integer ratated sorted array and duplicates are allowed
	* param target :  an integer to be search
	* return : a boolean
	*/
public:
	bool search(vector<int> &A, int target) {
		// write your code here
		if (A.empty())
		{
			return false;
		}//if

		int p = searchMin(A);
		bool ret = search1(A, target, 0, p - 1);
		return ret ? ret : search1(A, target, p, A.size() - 1);
	}

	/*��ת�������в�����Сֵ*/
	int searchMin(vector<int> &A)
	{
		if (A.empty())
		{
			return -1;
		}//if

		int lhs = 0, rhs = A.size() - 1;
		if (A[lhs] < A[rhs])
		{
			return lhs;
		}//if

		while (lhs < rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (A[mid] >= A[rhs])
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

	bool search1(vector<int> &A, int target, int lhs, int rhs)
	{
		if (A.empty() || lhs > rhs)
		{
			return false;
		}//if

		while (lhs <= rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (A[mid] == target)
			{
				return true;
			}//if
			else if (A[mid] > target)
			{
				rhs = mid - 1;
			}//elif
			else{
				lhs = mid + 1;
			}//else
		}//while

		return false;
	}
};