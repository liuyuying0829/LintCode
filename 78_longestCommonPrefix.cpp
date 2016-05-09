/*
78 �����ǰ׺

��k���ַ�����������ǵ������ǰ׺(LCP)

����

�� "ABCD" "ABEF" �� "ACEF" ��,  LCP Ϊ "A"

�� "ABCDEFG", "ABCEFG", "ABCEFA" ��, LCP Ϊ "ABC"

*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
     //��������ǰ׺
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if(strs.empty())
        {
            return "";
        }//if
        
        int n = strs.size();
        string pRet = strs[0];
        
        for(int i=1; i<n; ++i)
        {
            string tmp = pRet;
            pRet = "";
            
            int len = min(tmp.length() , strs[i].length());
            for(int j=0; j<len; ++j)
            {
                if(tmp[j] == strs[i][j])
                {
                    pRet += tmp[j];
                }//if
                else
                {
                    break;
                }//else
            }//for
            
        }//for
        
        return pRet;
    }
};