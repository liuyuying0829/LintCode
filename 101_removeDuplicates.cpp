/*
101 ɾ�����������е��ظ����� II

������ɾ���ظ����֡���

�������������������ظ�����δ���



������ʵ���������Ƿ�����������⣿ Yes
����
��������A =[1,1,1,2,2,3]����ĺ���Ӧ�÷��س���5����ʱA=[1,1,2,2,3]��

*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.empty())
        {
            return 0;
        }//if
        
        int n = nums.size(), k=0, times=1;
        for(int i=1; i<n; ++i)
        {
            if(nums[i] != nums[k])
            {
                nums[++k] = nums[i];
                times = 1;
            }else if(nums[i] == nums[k]){
                if(times >= 2)
                {
                    continue;
                }else{
                    nums[++k] = nums[i];
                    ++times;
                }//else
            }//elif
        }//for
        
        nums.resize(k+1);
        return k+1;
    }
};