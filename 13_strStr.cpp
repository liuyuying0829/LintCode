/*
13 �ַ�������

����һ�������� source �ַ�����һ�� target �ַ�������Ӧ���� source �ַ������ҳ� target �ַ������ֵĵ�һ��λ��(��0��ʼ)����������ڣ��򷵻� -1��

����
��� source = "source" �� target = "target"������ -1��

��� source = "abcdabcdefg" �� target = "bcd"������ 1��
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(source == NULL || target == NULL)
        {
            return -1;
        }//if

        /*��ͨģʽƥ���㷨*/
        int sLen = strlen(source),tLen = strlen(target);
        
        int i=0,j=0;
        while(i<sLen && j<tLen)
        {
            if(source[i] == target[j])
            {
                ++i;
                ++j;
            }//if
            else{
                i = i - j + 1;
                j = 0;
            }
        }
        
        if(j >= tLen)
        {
            return i-tLen;
        }else{
            return -1;
        }
    }
    
    
};
