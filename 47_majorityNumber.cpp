/*
47 ��Ԫ�� II

����һ���������飬�ҵ���Ԫ�أ����������еĳ��ִ����ϸ��������Ԫ�ظ���������֮һ��

����
��������[1,2,1,2,1,3,3] ���� 1
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int n = nums.size();
        int num1 = INT_MIN, times1=0;
        int num2 = INT_MIN, times2=0;
        
        for(int i=0 ;i<n ;++i)
        {
            int tmp = nums[i];
            if(num1 == tmp)
            {
                ++times1;
            }//if
            else if(num2 == tmp)
            {
                ++times2;
            }//elif
            else if(times1 == 0)
            {
                num1 = tmp;
                times1 = 1;
            }//elif
            else if(times2 == 0)
            {
                num2 = tmp;
                times2 = 1;
            }//elif
            else{
                --times1;
                --times2;
            }//else
        }//for
        
        times1 = 0;
        times2 = 0;
        for(int i=0; i<n; ++i)
        {
            if(nums[i] == num1)
            {
                ++times1;
            }else if(nums[i] == num2)
            {
                ++times2;
            }//elif
        }//for
        
        return times1 > times2 ? num1 : num2;
    }
};
