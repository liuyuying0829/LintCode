/*
158 �����ַ����Ǳ�λ��

д��һ������ anagram(s, t) �ж������ַ����Ƿ����ͨ���ı���ĸ��˳����һ�����ַ�����

����
���� s = "abcd"��t="dcab"������ true.
���� s = "ab", t = "ab", ���� true.
���� s = "ab", t = "ac", ���� false.
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};