/*
32 ��С�Ӵ�����

����һ���ַ���source��һ��Ŀ���ַ���target�����ַ���source���ҵ���������Ŀ���ַ�����ĸ���Ӵ���
�����source��û���������Ӵ�������""������ж���������Ӵ������س�����С���Ӵ���
˵��
�ڴ𰸵��Ӵ��е���ĸ��Ŀ���ַ������Ƿ���Ҫ������ͬ��˳��
��������Ҫ��
����
����source = "ADOBECODEBANC"��target = "ABC" ����Ҫ��Ľ�  "BANC"
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* @param source: A string
	* @param target: A string
	* @return: A string denote the minimum window
	*          Return "" if there is no such a string
	*/
	string minWindow(string &source, string &target) {
		// write your code here
		if (source.empty() || target.empty())
			return "";

		int sLen = source.length(), tLen = target.length();
		vector<int> sHash(256, 0), tHash(256, 0);
		/*����Դ����ӳ�䣬�洢ÿ���ַ��ĳ��ִ���*/
		for (int i = 0; i < tLen; ++i)
		{
			++tHash[target[i]];
		}//for

		/*��¼����Ҫ����Ӵ���λ�ã��Լ��ҵ����ַ�����*/
		int beg = -1, end = sLen, found = 0, minLen = sLen;
		for (int i = 0, start = i; i < sLen; ++i)
		{
			++sHash[source[i]];
			/*���µ�ǰ�ҵ����ַ�����*/
			if (sHash[source[i]] <= tHash[source[i]])
				++found;
			/*�ж��Ƿ��ҵ������ַ�*/
			if (found == tLen)
			{
				/*��Դ����ͷδ������Ŀ�괮���ַ�����*/
				while (start < i && sHash[source[start]] > tHash[source[start]])
				{
					--sHash[source[start]];
					++start;
				}//while
				/*�ҵ�����Ҫ���Ӵ�����βλ��start �� i*/
				if (i - start < minLen)
				{
					minLen = i - start;
					beg = start;
					end = i;
				}//if
				/*�������Ӵ��Ŀ�ͷλ�ã�Ѱ����һ���Ӵ�*/
				--sHash[source[start++]];
				--found;
			}//if
		}//for

		/*���begֵΪ-1��˵���������������Ӵ�*/
		if (beg == -1)
			return "";
		else
			return source.substr(beg, end - beg + 1);
	}
};

int main()
{
	Solution s;
	string source = "ADOBECODEBANC", target = "BANC";

	cout << s.minWindow(source, target) << endl;

	system("pause");
	return 0;
}