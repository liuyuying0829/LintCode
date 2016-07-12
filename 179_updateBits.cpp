/*
179 ���¶�����λ

��������32λ������N��M���Լ�����������λ��λ��i��j��дһ��������ʹ��N�еĵ�i��jλ����M��M����N�дӵ�iΪ��ʼ����jλ���Ӵ���

����
����N = (10000000000)2��M = (10101)2�� i = 2, j = 6

���� N = (10001010100)2
*/
class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        m <<= i;    
        int factor = 1;    
        
        factor <<= i;    
        int step = j-i+1;    
        while (step > 0)    
        {    
            n &= (~factor);    
            factor <<= 1;    
            step--;    
        }    
    
        return n ^ m; 
        
    }
};