/*
 8 ��ת�ַ���

 ����
����һ���ַ�����һ��ƫ����������ƫ������ת�ַ���(����������ת)

����
�����ַ��� "abcdefg".

offset=0 => "abcdefg"
offset=1 => "gabcdef"
offset=2 => "fgabcde"
offset=3 => "efgabcd"
��ս
��������ԭ����ת��ʹ��O(1)�Ķ���ռ�
*/

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        if(str.empty())
        {
            return ;
        }//if
        
        int len = str.size();
        offset %= len;
        
        reverse(str.begin(),str.begin()+len-offset);
        reverse(str.begin()+len-offset, str.end());
        reverse(str.begin(),str.end());
    }
};
