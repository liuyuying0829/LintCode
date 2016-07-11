/*
181 ������Aת��ΪB

���Ҫ������Aת��ΪB����Ҫ�ı���ٸ�bitλ��

����
���31ת��Ϊ14����Ҫ�ı�2��bitλ��

(31)10=(11111)2

(14)10=(01110)2
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        return count1Bits(a ^ b);
    }
    
    int count1Bits(int n)
    {
        int count = 0;
        while(n)
        {
            ++count;
            n = n & (n-1);
        }//while
        
        return count;
    }
};