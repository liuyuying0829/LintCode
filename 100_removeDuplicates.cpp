/*
100 ɾ�����������е��ظ�����

����һ���������飬��ԭ������ɾ���ظ����ֵ����֣�ʹ��ÿ��Ԫ��ֻ����һ�Σ����ҷ����µ�����ĳ��ȡ�

��Ҫʹ�ö��������ռ䣬������ԭ��û�ж���ռ����������ɡ�

������ʵ���������Ƿ�����������⣿ Yes
����
��������A =[1,1,2]����ĺ���Ӧ�÷��س���2����ʱA=[1,2]��
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
        
        int n = nums.size(),k=0;
        
        for(int i=1;i<n;++i)
        {
            if(nums[i] != nums[k])
            {
                nums[++k] = nums[i];
            }//if
        }//for
        nums.resize(k+1);
        return k+1;
    }
};