/*
 46 ��Ԫ��

����һ���������飬�ҳ���Ԫ�أ����������еĳ��ִ����ϸ��������Ԫ�ظ����Ķ���֮һ��

����
��������[1,1,1,1,2,2,2]������ 1

��ս
Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        if(nums.empty())
        {
            return -1;
        }//if
        
        int len = nums.size();
        int ret = nums[0],times = 1;
        for(int i=1;i<len;++i)
        {
            if(times == 0)
            {
                ret = nums[i];
                times = 0;
            }//if
            else if(nums[i] == ret)
            {
                ++times;
            }//elif
            else{
                --times;
            }//else
        }//for
        return ret;
    }
};
