/*
 53 ��ת�ַ���

����һ���ַ����������ת�ַ����е�ÿ�����ʡ�

˵��
���ʵĹ��ɣ��޿ո���ĸ����һ������
�����ַ����Ƿ����ǰ������β��ո񣿿��԰��������Ƿ�ת����ַ����ܰ���
��δ����������ʼ�Ķ���ո��ڷ�ת�ַ����м�ո���ٵ�ֻ��һ��
����
����s = "the sky is blue"������"blue is sky the"
*/

class Solution {
public:
	/**
	* @param s : A string
	* @return : A string
	*/
	string reverseWords(string s) {
		// write your code here
		if (s.empty())
		{
			return s;
		}//if

		int len = s.length(), i, beg;
		string ret = "";
		for (i = 0, beg = 0; i<len; ++i)
		{
			if (s[i] == ' ')
			{
				string tmp = s.substr(beg, i - beg);
				reverse(tmp.begin(), tmp.end());
				ret = ret + tmp +" ";
				beg = i + 1;
			}//if
			
		}//for
		string tmp = s.substr(beg, i - beg);
		reverse(tmp.begin(), tmp.end());
		
		ret += tmp;

		reverse(ret.begin(), ret.end());

		return ret;
	}
};