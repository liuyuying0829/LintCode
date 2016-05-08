/*
76  �����������

����һ���������У��ҵ�����������У�LIS��������LIS�ĳ��ȡ�

����������еĶ��壺

�������������������һ������ĸ����������ҵ�һ�������ܳ����ɵ͵������е������У����������в�һ���������Ļ���Ψһ�ġ�
https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
����

���� [5,4,1,2,3]��LIS �� [1,2,3]������ 3
���� [4,2,4,5,3,7]��LIS �� [4,4,5,7]������ 4
*/

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
     
    //��̬�滮
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if(nums.empty())
        {
            return 0;
        }//if
        
        vector<int> dp = getDp1(nums);
        int maxLen = 0, len = dp.size();
        for(int i=0; i<len; ++i)
        {
            if(dp[i] > maxLen)
            {
                maxLen = dp[i];
            }//if
        }//for
        
        return maxLen;
    }
    
    //O(n^2)�ĸ��Ӷ�
    vector<int> getDp1(vector<int> &nums)
    {
        if(nums.empty())
        {
            return vector<int>();
        }//if
        
        int len = nums.size();
        vector<int> dp(len, 0);
        for(int i=0; i<len; ++i)
        {
            dp[i] = 1;
            for(int j=0; j<i; ++j)
            {
                if(nums[i] >= nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }//if
            }//for
        }//for
        
        return dp;
    }
};
