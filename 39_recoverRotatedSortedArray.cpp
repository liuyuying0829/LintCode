/*
 39 �ָ���ת��������

����һ����ת�������飬��ԭ�ػָ�������

˵��
ʲô����ת���飿

���磬ԭʼ����Ϊ[1,2,3,4], ������ת���������[1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]
����
[4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]

��ս
ʹ��O(1)�Ķ���ռ��O(n)ʱ�临�Ӷ�
*/
class Solution {
public:
	void recoverRotatedSortedArray(vector<int> &nums) {
		// write your code here
		if (nums.empty())
		{
			return;
		}//if

		int len = nums.size();
		int minNum = nums[0], minIdx = 0;
		for (int i = 1; i < len; ++i)
		{
			if (nums[i] < minNum)
			{
				minNum = nums[i];
				minIdx = i;
			}//if
		}//for

		if (minIdx == 0)
		{
			return;
		}//if

		reverse(nums, 0, minIdx - 1);
		reverse(nums, minIdx, len - 1);
		reverse(nums, 0, len - 1);
		return;
	}

	void reverse(vector<int> &nums, int beg, int end)
	{
		if (nums.empty() || beg >= end)
		{
			return;
		}//if

		while (beg < end)
		{
			exchange(nums[beg++], nums[end--]);
		}//while
	}

	void exchange(int &a, int &b)
	{
		if (a == b)
		{
			return;
		}//if

		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
};