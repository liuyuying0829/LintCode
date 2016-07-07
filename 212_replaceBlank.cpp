/*
212 �ո��滻

���һ�ַ�������һ���ַ����е����пո��滻�� %20 ������Լ�����ַ������㹻�Ŀռ��������µ��ַ�������õ����ǡ���ʵ�ġ��ַ����ȡ�

��ĳ�����Ҫ���ر��滻����ַ����ĳ��ȡ�

 ע������

���ʹ�� Java �� Python, �����������ַ������ʾ�ַ�����

����
�����ַ���"Mr John Smith", ����Ϊ 13

�滻�ո�֮�󣬲����е��ַ�����Ҫ��Ϊ"Mr%20John%20Smith"�����Ұ��³��� 17 ��Ϊ������ء�
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        if(string == NULL || length <= 0)
        {
            return 0;
        }//if
        
        int len = 0, blankNum = 0;
        while(string[len] != '\0')
        {
            if(string[len] == ' ')
            {
                ++blankNum;
            }
            ++len;
        }//while
        
        int newLen = len + 2 * blankNum;
       
        for(int i=newLen-1,j=len-1; i>=0 && j>=0;--j)
        {
            if(string[j] == ' ')
            {
                string[i--] = '0';
                string[i--] = '2';
                string[i--] = '%';
            }//if
            else{
                string[i--] = string[j];
            }//else
        }//for
        
        return newLen;
    }
};  