/*
64 �ϲ��������� II

�ϲ������������������A��B���һ���µ����顣
 
ע������

����Լ���A�����㹻�Ŀռ䣨A����Ĵ�С���ڻ����m+n��ȥ���B�е�Ԫ�ء�

����
���� A = [1, 2, 3, empty, empty], B = [4, 5]

�ϲ�֮�� A ����� [1,2,3,4,5]
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int k = m + n - 1;
        int i = m-1, j = n-1;
        
        while(i >= 0 && j >= 0)
        {
            if(A[i] > B[j])
            {
                A[k--] = A[i--];
            }else{
                A[k--] = B[j--];
            }//else
        }//while
        
        while(j >= 0)
        {
            A[k--] = B[j--];
        }//while
    }
};