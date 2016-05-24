/*
48 ��Ԫ�� III

����һ���������飬�ҵ���Ԫ�أ����������еĳ��ִ����ϸ��������Ԫ�ظ�����1/k��

����
�������� [3,1,2,3,2,3,3,4,4,4] ���� k = 3������ 3
*/
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
	/**
	* @param nums: A list of integers
	* @param k: As described
	* @return: The majority number
	*/
	int majorityNumber(vector<int> nums, int k) {
		// write your code here
		int n = nums.size();

		vector<int> vals(k - 1, INT_MIN), times(k - 1, 0);

		for (int i = 0; i<n; ++i)
		{
			int tmp = nums[i];
			bool flag = false;
			/*��k-1���ؼ��ֱȽϣ������ظ�����*/
			if (!flag)
			{
				for (int j = 0; j < k - 1; ++j)
				{
					if (tmp == vals[j])
					{
						++times[j];
						flag = true;
						break;
					}//if
				}//for
			}
			
			if (!flag)
			{
				for (int j = 0; j < k - 1; ++j)
				{
					if (times[j] == 0)
					{
						vals[j] = tmp;
						times[j] = 1;
						flag = true;
						break;
					}//if
				}//for
			}//if
			
			if (!flag)
			{
				for (int j = 0; j < k - 1; ++j)
				{
					--times[j];
				}//for
			}//if
			
		}//for

		/*��0 k-1���ؼ��ִ���*/
		for (int j = 0; j<k - 1; ++j)
		{
			times[j] = 0;
		}//for

		/*��¼ÿ���ؼ��ֵ�ʵ�ʴ���*/
		for (int i = 0; i<n; ++i)
		{
			int tmp = nums[i];
			for (int j = 0; j<k - 1; ++j)
			{
				if (tmp == vals[j])
				{
					++times[j];
					break;
				}//if
			}//for
		}//for

		/*���ִ������ı���1/k����Ԫ��*/
		int pos = -1, maxTimes = 0;
		for (int j = 0; j<k - 1; ++j)
		{
			if (times[j] > maxTimes)
			{
				maxTimes = times[j];
				pos = j;
			}//if
		}//for

		return vals[pos];
	}
};

int main()
{
	vector<int> v = { 3,1,2,3,2,3,3,4,4,4 };
	Solution s;
	cout << s.majorityNumber(v, 3) << endl;

	system("pause");
	return 0;
}