/*
159 Ѱ����ת���������е���Сֵ

����һ����ת�������������ʼλ����δ֪�ģ�����0 1 2 4 5 6 7 ���ܱ����4 5 6 7 0 1 2����

����Ҫ�ҵ�������С��Ԫ�ء�

����Լ��������в������ظ���Ԫ�ء�

����
����[4,5,6,7,0,1,2]  ���� 0
*/

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        if(num.empty())
        {
            return -1;
        }
        
        int len = num.size();
        int lhs = 0, rhs = len-1;
        while(num[lhs] >= num[rhs])
        {
            if(rhs - lhs == 1)
            {
                return num[rhs];
            }//if
            
            int mid = (lhs + rhs) / 2;
            
            if(num[lhs] == num[rhs] && num[lhs] == num[mid])
            {
                return midInorder(num, lhs, rhs);
            }
            if(num[mid] >= num[lhs])
            {
                lhs = mid;
            }else if(num[mid] <= num[rhs]){
                rhs = mid;
            }
        }
        return num[lhs];
    }
    
    int midInorder(vector<int> &num, int lhs, int rhs)
    {
        if(num.empty() || lhs <0 || rhs >= num.size())
        {
            return -1;
        }
        int ret = num[lhs];
        for(int i=lhs+1; i<=rhs; ++i)
        {
            if(ret > num[i])
            {
                ret = num[i];
            }
        }
        return ret;
    }
};