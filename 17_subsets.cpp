/*
17 �Ӽ�
����һ������ͬ�����ļ��ϣ����������е��Ӽ�

����
��� S = [1,2,3]�������µĽ⣺

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
	/**
	* @param S: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	/*1. �ݹ�ʵ��*/
	vector<vector<int> > subsets1(vector<int> &nums) {
		// write your code here
		if (nums.empty())
		{
			return vector<vector<int>>(1, vector<int>());
		}//if

		int len = nums.size();
		vector<int> tmp(nums.begin(), nums.begin() + len - 1);
		vector<vector<int>> tmpSets = subsets1(tmp);

		vector<vector<int>> ret;
		int tmpLen = tmpSets.size();
		for (int i = 0; i<tmpLen; ++i)
		{
			ret.push_back(tmpSets[i]);
			tmpSets[i].push_back(nums[len - 1]);
			ret.push_back(tmpSets[i]);
		}//for

		return ret;
	}

	/*�ǵݹ�ʵ��*/
	vector<vector<int> > subsets(vector<int> &nums) {
		// write your code here
		if (nums.empty())
		{
			return vector<vector<int>>(1, vector<int>());
		}//if

		int len = nums.size();
		vector<vector<int>> ret;
		ret.push_back(vector<int>());
		for (int i = 0; i < len; ++i)
		{
			int tmpLen = ret.size();
			for (int j = 0; j < tmpLen;++j)
			{
				vector<int> tmp = ret[j];
				tmp.push_back(nums[i]);
				ret.push_back(tmp);
			}//for
		}//for

		return ret;
	}
};
