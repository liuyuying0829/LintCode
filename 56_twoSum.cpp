/*
56 ����֮��

��һ���������飬�ҵ�������ʹ�����ǵĺ͵���һ����������target��

����Ҫʵ�ֵĺ���twoSum��Ҫ���������������±�, ���ҵ�һ���±�С�ڵڶ����±ꡣ
ע�������±�ķ�Χ��1��n��������0��ͷ��
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        if(nums.empty())
        {
            return vector<int>();
        }//if
        
        int len = nums.size();
        vector<int> ret;
        for(int i=0; i<len; ++i)
        {
            for(int j=i+1; j<len; ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    ret.push_back(i+1);
                    ret.push_back(j+1);
                    return ret;
                }//if
            }//for
        }//for
        
        return vector<int>();
    }
};
