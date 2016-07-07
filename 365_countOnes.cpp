/*
365 ���������ж��ٸ�1

������һ�� 32 λ�������Ķ����Ʊ�ʽ���ж��ٸ� 1.

����
���� 32 (100000)������ 1

���� 5 (101)������ 2

���� 1023 (111111111)������ 9
*/

class Solution {
public:
	/**
	* @param num: an integer
	* @return: an integer, the number of ones in num
	*/
	int countOnes(int num) {
		// write your code here
		int count = 0;
		while (num)
		{
			++count;
			num = num & (num - 1);
		}//while

		return count;
	}

	int countOnes1(int num)
	{
		int count = 0;
		unsigned int flag = 1;
		while (flag != 0)
		{
			if (num & flag)
			{
				++count;
			}
			flag <<= 1;
		}
	}
};