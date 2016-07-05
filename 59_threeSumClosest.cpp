/*
59 ��ӽ�������֮��

��һ������ n ������������ S, �ҵ������������ target ��ӽ�����Ԫ�飬�������������ĺ͡�

ֻ��Ҫ������Ԫ��֮�ͣ����践����Ԫ�鱾��

����
���� S = [-1, 2, 1, -4] and target = 1. ����ӽ� 1 ����Ԫ���� -1 + 2 + 1 = 2.
*/
class Solution {
public:
	/**
	* @param numbers: Give an array numbers of n integer
	* @param target: An integer
	* @return: return the sum of the three integers, the sum closest target.
	*/
	int threeSumClosest(vector<int> nums, int target) {
		// write your code here
		if (nums.empty())
		{
			return 0;
		}

		int len = nums.size(), minR = nums[0] + nums[1] + nums[2];
		for (int i = 0; i<len; ++i)
		{
			for (int j = i + 1; j<len; ++j)
			{
				for (int k = j + 1; k<len; ++k)
				{
					int tmpSum = nums[i] + nums[j] + nums[k];

					if (abs(minR - target) >= abs(target - tmpSum))
					{
						minR = tmpSum;
					}//if
				}//for
			}//for
		}//for

		return minR;
	}
};
