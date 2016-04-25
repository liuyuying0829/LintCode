/*
 55 �Ƚ��ַ���

�Ƚ������ַ���A��B��ȷ��A���Ƿ����B�����е��ַ����ַ���A��B�е��ַ����� ��д��ĸ

�� A �г��ֵ� B �ַ�������ַ�����Ҫ������������

����
���� A = "ABCD" B = "ACD"������ true

���� A = "ABCD" B = "AABC"�� ���� false
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        if(B.empty())
        {
            return true;
        }//if
        
        int lA = A.length() , lB = B.length();
        vector<int> v(256,0);
        for(int i=0; i<lA; ++i)
        {
            ++v[A[i]];
        }//for
        
        for(int j=0; j<lB; ++j)
        {
            --v[B[j]];
            if(v[B[j]] < 0)
            {
                return false;
            }//if
        }//for
        
        return true;
    }
};
