/*
142 O(1)ʱ����2���ݴ�
�� O(1) ʱ�������� n �Ƿ��� 2 ���ݴΡ�
O(1) ʱ�临�Ӷ�

����
n=4������ true;

n=5������ false.
*/

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
		// write your code here
		if(n <= 0)
		    return false;
		int ret = n & (n - 1);
		return ret == 0 ? true : false;
	}
};