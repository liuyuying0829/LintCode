/*
138 ������֮��

����һ���������飬�ҵ���Ϊ��������顣��Ĵ���Ӧ�÷�������Ҫ������������ʼλ�úͽ���λ��

����
���� [-3, 1, 2, -3, 4]������[0, 2] ���� [1, 3].
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        int len = nums.size();
        
        for(int i=0; i<len; ++i)
        {
            int sum = nums[i];
            if(sum == 0)
            {
                vector<int> ret;
                ret.push_back(i);
                ret.push_back(i);
                return ret;
            }//if
            
            for(int j=i+1; j<len; ++j)
            {
                sum += nums[j];
                if(sum == 0)
                {
                    vector<int> ret;
                    ret.push_back(i);
                    ret.push_back(j);
                    
                    return ret;
                }//if
            }//for
        }//for
        
        return vector<int>();
    }
};