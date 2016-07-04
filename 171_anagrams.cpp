/*
171 �����ַ���

����һ���ַ�������S���ҵ��������е������ַ���(Anagram)�����һ���ַ����������ַ�������ô������һ����ĸ������ͬ����˳��ͬ���ַ���Ҳ��S�С�

���е��ַ�����ֻ����Сд��ĸ

����
�����ַ������� ["lint","intl","inlt","code"]

���� ["lint","inlt","intl"]
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        if(strs.empty())
        {
            return vector<string>();
        }//if
        
        int len = strs.size();
        
        map<string,int> m;
        for(int i=0; i<len; ++i)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            m[t]++;
        }//for
        
        vector<string> ret;
        for(int i=0;i<len;++i)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            if(m[t] > 1)
            {
                ret.push_back(strs[i]);
            }//if
        }//for
        return ret;
    }
    
   
};
