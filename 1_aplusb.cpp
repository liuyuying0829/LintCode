/*
������������a��b, �����ǵĺ�, ������ʹ�� + ����ѧ�������
˵��
a��b���� 32λ ����ô��

�ǵ�
�ҿ���ʹ��λ�����ô��

��Ȼ����
����
��� a=1 ���� b=2������3
*/
class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        if (b == 0)
        {
               return a;
        }
        else {
            int c = a ^ b;
            int carry = (a & b) << 1;
            return aplusb(c,carry);
        }
    }
};