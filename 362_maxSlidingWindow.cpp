/*
362  �������ڵ����ֵ

����һ�����ܰ����ظ����������飬��һ����СΪ k �Ļ�������, �������������л���������ڣ��ҵ�������ÿ�������ڵ����ֵ��

����
�������� [1,2,7,7,8], �������ڴ�СΪ k = 3. ���� [7,7,8].

���ͣ�

�ʼ�����ڵ�״̬���£�

[|1, 2 ,7| ,7 , 8], ���ֵΪ 7;

Ȼ�󴰿������ƶ�һλ��

[1, |2, 7, 7|, 8], ���ֵΪ 7;

��󴰿��������ƶ�һλ��

[1, 2, |7, 7, 8|], ���ֵΪ 8.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
	/**
	* @param nums: A list of integers.
	* @return: The maximum number inside the window at each moving.
	*/
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		// write your code here
		if (nums.empty() || nums.size() < k)
		{
			return vector<int>();
		}

		int n = nums.size();
		vector<int> ret;
		deque<int> idx;
		/**/
		for (int i = 0; i < k; ++i)
		{
			while (!idx.empty() && nums[i] >= nums[idx.back()])
			{
				idx.pop_back();
			}//while
			idx.push_back(i);
		}

		for (int i = k; i < n; ++i)
		{
			ret.push_back(nums[idx.front()]);

			while (!idx.empty() && nums[i] >= nums[idx.back()])
				idx.pop_back();

			if (!idx.empty() && idx.front() <= (i - k))
				idx.pop_front();

			idx.push_back(i);
		}
		ret.push_back(nums[idx.front()]);

		return ret;
	}
	/*O(n^2)�ⷨ*/
	vector<int> maxSlidingWindow1(vector<int> &nums, int k) {
		// write your code here
		if (nums.empty())
		{
			return vector<int>();
		}

		int n = nums.size();
		vector<int> ret;
		for (int i = 0; i<n - k + 1; ++i)
		{
			int maxNum = nums[i];
			for (int j = i + 1; j<i + k; ++j)
			{
				if (maxNum < nums[j])
				{
					maxNum = nums[j];
				}//if
			}//for

			ret.push_back(maxNum);
		}//for

		return ret;
	}
};

int main()
{
	vector<int> v = { 1,2,7,7,2 };

	vector<int> ret = Solution().maxSlidingWindow(v, 3);

	system("pause");
	return 0;
}