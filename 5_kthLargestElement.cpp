/*
5  ��k��Ԫ��
��Ŀ
���������ҵ���k���Ԫ��
����
�������� [9,3,2,4,8]���������Ԫ���� 4

�������� [1,2,3,4,5]����һ���Ԫ���� 5���ڶ����Ԫ���� 4���������Ԫ���� 3���Դ�����

��ս
Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
*/

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        if(nums.empty() || k <= 0)
        {
            return -1;
        }//if
        
        int len = nums.size();
        int low = 0 , high = len - 1;
        int idx = partition(nums, low , high);
        //ѡ�ñȽϵ�������С
        while(idx != (len - k))
        {
            if(idx < (len - k))
            {
                low = idx + 1;
            }else
            {
                high = idx -1 ;
            }
            
            idx = partition(nums , low , high);
        }//while
        
        return nums[idx];
    }
    
    int partition(vector<int> &nums , int low , int high)
    {
        if(nums.empty())
        {
            return -1;
        }//if
        
        int i = low - 1;
        int x = nums[high];
        for(int j=low; j<high; ++j)
        {
            if(nums[j] < x)
            {
                ++i;
                exchange(nums[i] , nums[j]);
            }//if
        }//for
        
        exchange(nums[i+1] , nums[high]);
        return i+1;
    }
    
    void exchange(int &a , int &b)
    {
        //ע����򽻻�������
        if(a == b)
        {
            return;
        }
        a ^= b;
        b ^= a;
        a ^= b;
    }
};