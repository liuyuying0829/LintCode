/*
 41 ���������

����һ���������飬�ҵ�һ���������͵������飬���������͡�

 ע������

���������ٰ���һ����

����
��������[?2,2,?3,4,?1,2,1,?5,3]������Ҫ���������Ϊ[4,?1,2,1]��������Ϊ6

��ս
Ҫ��ʱ�临�Ӷ�ΪO(n)
*/
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if(nums.empty())
        {
            return 0;
        }//if
        
        int len = nums.size();
        int maxSum = nums[0] , tmpSum = nums[0];
        for(int i=1;i<len;++i)
        {
            if(tmpSum < 0)
            {
                tmpSum = nums[i];
                continue;
            }else{
                if(tmpSum > maxSum)
                {
                    maxSum = tmpSum;
                }//if
                tmpSum += nums[i];
            }
        }//for
        if(tmpSum > maxSum)
        {
            maxSum = tmpSum;
        }//if
        return maxSum;
    }
};
