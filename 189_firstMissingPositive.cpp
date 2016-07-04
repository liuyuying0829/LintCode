/*
189 ��ʧ�ĵ�һ��������

����һ��������������飬�ҳ�����û�г��ֵ���С��������

����
������� [1,2,0], return 3
������� [3,4,-1,1], return 2
*/

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        if(A.empty())
        {
            return 1;
        }//if
        
        set<int> s(A.begin(),A.end());
        
        int cur = 1;
        
        for(auto iter=s.begin(); iter!=s.end(); ++iter)
        {
            if(*iter <= 0)
            {
                continue;
            }//if
            else if(*iter != cur)
            {
                return cur;
            }else{
                cur++;
            }//else
        }//for
        return cur;
        
    }
};