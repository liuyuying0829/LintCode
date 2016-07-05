/*
57 ����֮��

����һ����n������������S����S���ҵ���������a, b, c���ҵ�����ʹ��a + b + c = 0����Ԫ�顣

����Ԫ��(a, b, c)��Ҫ��a <= b <= c��

������ܰ����ظ�����Ԫ�顣

����
��S = {-1 0 1 2 -1 -4}, ����Ҫ���ص���Ԫ�鼯�ϵ��ǣ�

(-1, 0, 1)

(-1, -1, 2)
*/
class Solution {
public:
	/**
	* @param numbers : Give an array numbers of n integer
	* @return : Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int> > threeSum(vector<int> &nums) {
		// write your code here
		vector<vector<int>> ret;
		if (nums.empty())
		{
			return ret;
		}//if

		int len = nums.size();


		for (int i = 0; i<len; ++i)
		{
			vector<int> tmp(nums.begin() + i + 1, nums.end());
			vector<vector<int>> r = twoSum(tmp, 0 - nums[i]);

			int n = r.size();
			for (int j = 0; j<n; ++j)
			{
				r[j].push_back(nums[i]);
				sort(r[j].begin(), r[j].end());
				ret.push_back(r[j]);
			}//for
		}//for
		//ȥ��
		sort(ret.begin(), ret.end());
		ret.erase(unique(ret.begin(), ret.end()), ret.end());
		return ret;
	}

	vector<vector<int>> twoSum(vector<int> &nums, int target)
	{
		vector<vector<int>> ret;
		if (nums.empty())
		{
			return ret;
		}//if

		int len = nums.size();
		for (int i = 0; i<len; ++i)
		{
			for (int j = i + 1; j<len; ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					vector<int> v;
					v.push_back(nums[i]);
					v.push_back(nums[j]);

					sort(v.begin(), v.end());
					ret.push_back(v);
				}//if
			}//for
		}//for
		return ret;
	}
};