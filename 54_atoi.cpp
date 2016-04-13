/*
 54 ת���ַ���������

ʵ��atoi�����������һ���ַ���ת��Ϊ���������û�кϷ�������������0���������������32λ�����ķ�Χ������INT_MAX(2147483647)�����������������INT_MIN(-2147483648)����Ǹ�������

����
"10" =>10

"-1" => -1

"123123123123123" => 2147483647

"1.0" => 1
*/

class Solution {
public:
	/**
	* @param str: A string
	* @return An integer
	*/
	int atoi(string str) {
		// write your code here
		if (str.empty())
		{
			return 0;
		}//if
		int len = str.length();
		/*ɾ���ַ�����ͷ�����0*/
		int beg = 0;
		while (beg < len && (str[beg] == ' ' || str[beg] == '0'))
		{
			++beg;
		}//while

		/*ɾ���ַ�����β����ķ������ַ�*/
		int end = beg + 1;
		while (end < len && (str[end] >= '0' && str[end] <= '9'))
		{
			++end;
		}//while

		/*�õ���Ч�ַ���*/
		str = str.substr(beg, end - beg);
		if (!isValid(str))
		{
			return 0;
		}//if
		len = str.length();

		bool posi = str[0] == '-' ? false : true;
		int minq = INT_MIN / 10, minr = INT_MIN % 10;

		int sum = 0;
		for (int i = (!posi || str[0] == '+') ? 1 : 0; i<len; ++i)
		{
			if (str[i] == '.')
			{
				break;
			}//if

			int num = '0' - str[i];
			if ((sum < minq) || (sum == minq && num < minr))
			{
				/*���*/
				return posi ? INT_MAX : INT_MIN;
			}//if

			sum = sum * 10 + num;
		}//for

		/*���*/
		if (posi && sum == INT_MIN)
		{
			return INT_MAX;
		}//if

		return posi ? -sum : sum;
	}

	bool isValid(string str)
	{
		if (str.empty())
		{
			return true;
		}//if

		int len = str.length();
		if ((str[0] != '-' && str[0] != '+') && (str[0] < '0' || str[0] > '9'))
		{
			return false;
		}//if

		if ((str[0] == '-' || str[0] == '+') && (len == 1 || str[0] == '0' || str[0] == '.'))
		{
			return false;
		}//if

		if (str[0] == '0' && len > 1)
		{
			return false;
		}//if

		for (int i = 1; i<len; ++i)
		{
			if ((str[i] < '0' || str[i] > '9') && (str[i] != '.'))
			{
				return false;
			}//if

			if (str[i] == '.' && (i + 1) == len)
			{
				return false;
			}//elif

		}//for
		return true;

	}
};