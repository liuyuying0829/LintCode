/*
211 �ַ����û�

���������ַ����������һ���������ж�����һ���ַ����Ƿ�Ϊ��һ���ַ������û���

�û�����˼�ǣ�ͨ���ı�˳�����ʹ�������ַ�����ȡ�

����
"abc" Ϊ "cba" ���û���

"aabc" ���� "abcc" ���û���
*/

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        return A == B;
    }
};