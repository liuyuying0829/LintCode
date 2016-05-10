/*
80 ��λ��

����һ��δ������������飬�ҵ�����λ����

��λ���������������м�ֵ���������ĸ�����ż�������򷵻����������ĵ�N/2������
����

��������[4, 5, 1, 2, 3]�� ���� 3

��������[7, 9, 4, 5]������ 5

*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median1(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        return nums[(nums.size()-1)/2];
    }
    
    int median(vector<int> &nums)
    {
        if(nums.empty())
        {
            return 0;
        }//if
        
        int lhs = 0 , rhs = nums.size()-1;
        int mid = (lhs + rhs) / 2;
        
        int idx = partition(nums, lhs , rhs);
        while(idx != mid && lhs <= rhs)
        {
            if(idx < mid)
            {
                lhs = idx + 1;
            }else{
                rhs = idx - 1;
            }//if
            
            idx = partition(nums, lhs , rhs);
        }//while
        
        return nums[idx];
    }
    
    int partition(vector<int> &nums, int left, int high)
    {
        if(nums.empty() || left > high)
        {
            return -1;
        }//if
        
        int low = left-1, pivot = nums[high];
        for(int i=left; i<high; ++i)
        {
            if(nums[i] <= pivot)
            {
                ++low;
                exchange(nums[low], nums[i]);
            }//if
        }//for
        
        exchange(nums[low+1], nums[high]);
        return low+1;
    }//partition
    
    void exchange(int &a, int &b)
    {
        if(a == b)
        {
            return ;
        }//if
        
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};
