/*
81 ��λ�� II

�����ǲ��Ͻ�������ģ���ÿ�����һ���µ������������ͬʱ���ص�ǰ���������λ����

˵��

��λ���Ķ��壺

    ��λ���������������м�ֵ���������������n����������λ��ΪA[(n-1)/2]��
    ���磺����A=[1,2,3]����λ����2������A=[1,19]����λ����1��

����

������������������б�Ϊ��[1, 2, 3, 4, 5]���򷵻�[1, 1, 2, 2, 3]

������������������б�Ϊ��[4, 5, 1, 3, 2, 6, 0]���򷵻� [4, 4, 4, 3, 3, 3, 3]

������������������б�Ϊ��[2, 20, 100]���򷵻�[2, 2, 20]

*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    
    //����һ����������λ����ά�������ṹ 
     vector<int> medianII(vector<int> &nums) {
        // write your code here
        multiset<int> left, right;
        vector<int> res;
        bool flag = true;
        for (int n : nums) {
            int tmp = n;
            if (flag) {
                if (!right.empty() && n > *right.begin()) {
                    right.insert(n);
                    tmp = *right.begin();
                    right.erase(right.find(tmp));
                }
                left.insert(tmp);
            } else {
                if (!left.empty() && n < *left.rbegin()) {
                    left.insert(n);
                    tmp = *left.rbegin();
                    left.erase(left.find(tmp));
                }
                right.insert(tmp);
            }
            flag = !flag;
            res.push_back(*left.rbegin());
        }
        return res;
    } 
    
    /*�����������Դ������ǻᳬʱ*/
    vector<int> medianII_2(vector<int> &nums) {
        // write your code here
        if(nums.empty())
        {
            return vector<int>();
        }//if
        
       int len = nums.size();
       vector<int> ret,v;
       v.push_back(nums[0]);
       ret.push_back(nums[0]);
       
       for(int i=1; i<len; ++i)
       {
           v.push_back(nums[i]);
           ret.push_back(median(v));
       }//for
       
       return ret;
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

