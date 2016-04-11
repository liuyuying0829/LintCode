/*
����һ����������nums��һ������k���������飨���ƶ�����nums�е�Ԫ�أ���ʹ�ã�

����С��k��Ԫ���Ƶ����
���д��ڵ���k��Ԫ���Ƶ��ұ�
�������黮�ֵ�λ�ã��������е�һ��λ��i������nums[i]���ڵ���k��

����
��������nums=[3,2,2,1]�� k=2������ 1
*/
class Solution {
public:

    /*����һ�����ÿ��������˼��*/
	int partitionArray1(vector<int> &nums, int k) {
		// write your code here
		if (nums.empty())
		{
			return 0;
		}//if

		return partition(nums, 0, nums.size() - 1, k);
	}

    /*���������͵ؽ���*/
	int partitionArray(vector<int> &nums, int k)
	{
		if (nums.empty())
			return 0;

		int lhs = 0, rhs = nums.size() - 1;
		while (lhs < rhs)
		{
			while (lhs < nums.size() && nums[lhs] < k)
			{
				++lhs;
			}//while
			while (rhs >=0 && nums[rhs] >= k)
			{
				--rhs;
			}//while
			if (lhs < rhs)
			{
				exchange(nums[lhs], nums[rhs]);
			}//if
		}//for

		return rhs+1;
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

	int partition(vector<int> &nums, int low, int high, int k)
	{
		if (nums.empty() || low > high || high >= nums.size())
		{
			return -1;
		}//if
		int left = -1, x = k;
		for (int i = low; i <= high; ++i)
		{
			if (nums[i] < x)
			{
				++left;
				exchange(nums[left], nums[i]);
			}//if
		}//for

		return left + 1;
	}

};