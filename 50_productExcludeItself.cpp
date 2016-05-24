/*
60 �����޳�Ԫ�غ�ĳ˻�

����һ����������A��

����B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]�� ����B��ʱ���벻Ҫʹ�ó�����

����
����A=[1, 2, 3]������ BΪ[6, 3, 2]
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
     
     //ǰ׺��׺��˼��
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        vector<long long> A(n,0), B(n,0);
        B[n-1] = 1;
        for(int i=n-2; i>=0; --i)
        {
            B[i] = B[i+1] * nums[i+1];
        }//for
        
        A[0] = 1;
        for(int i=1; i<n; ++i)
        {
            A[i] = A[i-1] * nums[i-1];
        }//for
        
        for(int i=0; i<n; ++i)
        {
            B[i] *= A[i];
        }//for
        
        return B;
    }
};