/*
77 �����������

���������ַ������ҵ������������(LCS)������LCS�ĳ��ȡ�

˵��

����������еĶ��壺

    �������������������һ�����У�ͨ��2�������ҵ�����������У�ע�⣺��ͬ���Ӵ���LCS����Ҫ���������Ӵ������������ǵ��͵ļ������ѧ���⣬���ļ�����Ƚϳ���Ļ�������������Ϣѧ��Ҳ����Ӧ�á�
    https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

����

����"ABCD" �� "EDCA"�����LCS�� "A" (�� D��C)������1

���� "ABCD" �� "EACB"�����LCS��"AC"���� 2
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        
        if(A.empty() || B.empty())
        {
            return 0;
        }//if
        
        int aLen = A.size(), bLen = B.size();
        
        /*����dp[i][j]�ĺ������ַ���A[0...i]���ַ���B[0...j]������������г��ȣ������ң����ϵ��¼������dp*/
        vector<vector<int>> dp(aLen, vector<int>(bLen, 0));
        dp[0][0] = A[0] == B[0] ? 1 : 0;
        for(int i=1; i<aLen; ++i)
        {
            dp[i][0] = max(dp[i-1][0], A[i] == B[0] ? 1 : 0);
        }//for
        
        for(int j=1; j<bLen; ++j)
        {
            dp[0][j] = max(dp[0][j], A[0] == B[j] ? 1 : 0);
        }//for
        
        for(int i=1; i<aLen; ++i)
        {
            for(int j=1; j<bLen; ++j)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                
                if(A[i] == B[j])
                {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }//if
            }//for
        }//for
        
        return dp[aLen-1][bLen-1];
    }
};
