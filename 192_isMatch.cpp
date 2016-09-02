/*
192  ͨ���ƥ�� 

�ж��������ܰ���ͨ����������͡�*�����ַ����Ƿ�ƥ�䡣ƥ��������£�

'?' ����ƥ���κε����ַ���
'*' ����ƥ�������ַ������������ַ�������

��������ȫƥ�����ƥ��ɹ���

�����ӿ�����:
bool isMatch(const char *s, const char *p)

������ʵ���������Ƿ�����������⣿
����

һЩ���ӣ�

isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "*") �� true
isMatch("aa", "a*") �� true
isMatch("ab", "?*") �� true
isMatch("aab", "c*a*b") �� false
*/
class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        if(s == NULL && p == NULL)
            return true;
        if(s == NULL || p == NULL)
            return false;
            
            
        int sLen = strlen(s);
        int pLen = strlen(p);
        
        vector<vector<int>> dp(sLen+1,vector<int>(pLen+1,0));
        for(int i=1;i <=sLen ; ++i)
        {
            for(int j=1; j<=pLen; ++j)
            {
                dp[i][j] = 0;
            }//for
        }//for
        
        dp[0][0] = 1;
        for(int i=1; i<= sLen; ++i)
        {
            if(dp[i-1][0] == 1 && s[i-1] == '*')
            {
                dp[i][0] = 1;
            }else{
                dp[i][0] = 0;
            }//else
        }//for
        
        for(int j=1; j<=pLen; ++j)
        {
            if(dp[0][j-1] == 1 && p[j-1] == '*')
            {
                dp[0][j] = 1;
            }else{
                dp[0][j] = 0;
            }//else
        }//for
        
        for(int i=1;i<=sLen; ++i)
        {
            for(int j=1; j<=pLen; ++j)
            {
                if(s[i-1] == '*' || p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else if(s[i-1] == '?' || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else {
                    dp[i][j] = ((s[i-1] == p[j-1] ? 1 : 0) && dp[i-1][j-1]);
                }//else
            }//for
        }//for
        
        return dp[sLen][pLen];
    }
};