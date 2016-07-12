/*
371 �õݹ��ӡ����

�õݹ�ķ����ҵ���1������Nλ������

 ע������

���������ַ�ʽȥ�ݹ���ʵ�����ף�

recursion(i) {
    if i > largest number:
        return
    results.add(i)
    recursion(i + 1)
}
�������ַ�ʽ��ķѺܶ�ĵݹ�ռ䣬���¶�ջ��������ܹ��������ķ�ʽ���ݹ�ʹ�õݹ��������ֻ�� N ��ô��

����
���� N = 1, ����[1,2,3,4,5,6,7,8,9].

���� N = 2, ����[1,2,3,4,5,6,7,8,9,10,11,...,99].
*/

class Solution {
public:
	/**
	* @param n: An integer.
	* return : An array storing 1 to the largest number with n digits.
	*/
	vector<int> numbersByRecursion(int n) {
		// write your code here
		if (n == 0)
		{
			return vector<int>();
		}
		else if (n == 1) {
			vector<int> ret = { 1,2,3,4,5,6,7,8,9 };
			return ret;
		}
		else {
			vector<int> last = numbersByRecursion(n - 1);
			vector<int> ret = { 1,2,3,4,5,6,7,8,9 };

			for (vector<int>::iterator iter = last.begin(); iter != last.end(); ++iter)
			{
				for (int i = 0; i <= 9; ++i)
				{
					ret.push_back(*iter * 10 + i);
				}//for

			}//for
			return ret;
		}
	}
};