/*
75 Ѱ�ҷ�ֵ

�����һ����������(sizeΪn)������������ص㣺

    ����λ�õ������ǲ�ͬ��
    A[0] < A[1] ���� A[n - 2] > A[n - 1]

�ٶ�P�Ƿ�ֵ��λ��������A[P] > A[P-1]��A[P] > A[P+1]����������������һ����ֵ��λ�á�
ע������

������ܰ��������ֵ��ֻ���ҵ����е��κ�һ������
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        if(A.empty())
        {
            return -1;
        }//if
    
        for(int i=1; i<A.size()-1; ++i)
        {
            if(A[i] > A[i-1] && A[i] > A[i+1])
            {
                return i;
            }//if
        }//for
        
        return -1;
    }
};
