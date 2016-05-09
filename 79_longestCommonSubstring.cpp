/*
79 ������Ӵ�

���������ַ������ҵ�������Ӵ����������䳤�ȡ�

ע������
�Ӵ����ַ�Ӧ�������ĳ�����ԭ�ַ����У�����������������ͬ��

����

����A=��ABCD����B=��CBCE�������� 2

*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        if(A.empty() || B.empty())
        {
            return 0;
        }//if
        
        int aLen = A.size(), bLen = B.size();
        /*��̬�滮��ʱ�临�Ӷ�O(mn) �ռ临�Ӷ�O(mn��
        dp[i][j]��ʾ�����A[i]��B[j]��Ϊ�����Ӵ������һ���ַ�ʱ���Ӵ���󳤶�*/
        vector<vector<int>> dp(aLen, vector<int>(bLen,0));
        dp[0][0] = A[0] == B[0] ? 1 : 0;
        
        int maxLen = dp[0][0];
        
        for(int i=1; i<aLen; ++i)
        {
            dp[i][0] = A[i] == B[0] ? 1 : 0;
            maxLen = max(maxLen, dp[i][0]);
        }//for
        
        for(int j=1; j<bLen; ++j)
        {
            dp[0][j] = A[0] == B[j] ? 1 : 0;
            
            maxLen = max(maxLen, dp[0][j]);
        }//for
        
        
        for(int i=1; i<aLen; ++i)
        {
            for(int j=1; j<bLen; ++j)
            {
                if(A[i] == B[j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }//if
                else{
                    dp[i][j] = 0;
                }//if
                
                maxLen = max(maxLen, dp[i][j]);
            }//for
        }//for
        return maxLen;
    }
};
