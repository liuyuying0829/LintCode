/*
18  ������ά����
д��һ����Ч���㷨������ m �� n�����е�ֵ��

�����������������ԣ�

ÿ���е�����������������ġ�
ÿ�еĵ�һ����������һ�е����һ��������

����
�������о���

[
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
���� target = 3������ true
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty())
        {
            return false;
        }//if
        
        int m = matrix.size() , n = matrix[0].size();
        int row = 0 , col = n-1;
        while(row < m && col >= 0)
        {
            if(matrix[row][col] == target)
            {
                return true;
            }//if
            else if(matrix[row][col] < target)
            {
                ++row;
            }else{
                --col;
            }//else
        }//while
        
        return false;
    }
};
