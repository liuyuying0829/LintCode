/*
14  ���ֲ���
����һ��������������飨���򣩺�һ��Ҫ���ҵ�����target��
��O(logn)��ʱ����ҵ�target��һ�γ��ֵ��±꣨��0��ʼ����
���target�������������У�����-1��

����
������ [1, 2, 3, 3, 4, 5, 10] �ж��ֲ���3������2��
*/
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if(array.empty())
        {
            return -1;
        }//if
        
        int len = array.size();
        int lhs = 0, rhs = len-1;
        while(lhs <= rhs)
        {
            int mid = (lhs + rhs) / 2;
            if(array[mid] == target)
            {
                if(mid == 0)
                {
                    return mid;
                }//if
                else if(mid > 0 && array[mid-1] != target)
                {
                    return mid;
                }else{
                    rhs = mid - 1;
                }//else
            }else if(array[mid] > target)
            {
                rhs = mid - 1;
            }//elif
            else{
                lhs = mid + 1;
            }
        }//while
        return -1;
    }
};