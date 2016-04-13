/*
 38 ������ά���� II

д��һ����Ч���㷨������m��n�����е�ֵ���������ֵ���ֵĴ�����

�����������������ԣ�

ÿ���е�����������������ġ�
ÿһ�е��������ϵ���������ġ�
��ÿһ�л�ÿһ����û���ظ���������

����
�������о���

[

    [1, 3, 5, 7],

    [2, 4, 7, 8],

    [3, 5, 9, 10]

]

����target = 3������ 2

��ս
Ҫ��O(m+n) ʱ�临�ӶȺ�O(1) ����ռ�
*/
class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty())
        {
            return 0;
        }//if
        
        int m = matrix.size(),n=matrix[0].size();
        int r=0,c=n-1, count=0;
        while(r < m && c >= 0)
        { 
            if(matrix[r][c] == target)
            {
                ++count;
                ++r;
                --c;
            }//if
            else if(matrix[r][c] < target)
            {
                ++r;
            }else{
                --c;
            }//else
        }//while
        
        return count;
    }
};
