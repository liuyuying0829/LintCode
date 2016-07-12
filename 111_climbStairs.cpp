/*
111 ��¥��

������������¥�ݣ���Ҫn������ܵ��ﶥ������ÿ����ֻ����һ�����������������ж����ֲ�ͬ�ķ�������¥������

����
����n=3��1+1+1=1+2=2+1=3������3�в�ͬ�ķ���
*/
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        vector<int> ways(n+1,0);
        ways[0] = 1;
        ways[1] = 1;
        ways[2] = 2;
        
        for(int i=3; i<=n; ++i)
        {
            ways[i] = ways[i-1] + ways[i-2];
        }//for
        
        return ways[n];
        
    }
};
