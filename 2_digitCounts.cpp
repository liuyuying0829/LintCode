/*
��Ŀ����������k��0��n�еĳ��ֵĴ�����k������0~9��һ��ֵ
����
����n=12��k=1���� [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]�����Ƿ���1������5�� (1, 10, 11, 12)
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        if(n == 0)
        {
            return count1(0, k);
        }//if
        else{
            return digitCounts(k, n-1) + count1(n , k);
        }
    }
    
    int count1(int n, int k)
    {
        if(n == 0)
        {
            return k == 0 ? 1 : 0;
        }
        
        int num = 0;
        while(n)
        {
            if(n % 10 == k)
            {
                ++num;
            }//if
            n /= 10;
        }//while
        return num;
    }
};