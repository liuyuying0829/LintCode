/*
74 ��һ������Ĵ���汾

�����İ汾���Ǵ� 1 �� n ��������ĳһ�죬�����ύ�˴���汾�Ĵ��룬����������֮��汾�Ĵ����ڵ�Ԫ�����о��������ҳ���һ������İ汾�š�

�����ͨ�� isBadVersion �Ľӿ����жϰ汾�� version �Ƿ��ڵ�Ԫ�����г�������ӿ�����͵��÷�����������ע�Ͳ��֡�
ע������

���Ķ��������룬���ڲ�ͬ�����Ի�ȡ��ȷ�ĵ��� isBadVersion �ķ���������java�ĵ��÷�ʽ��VersionControl.isBadVersion

����

���� n=5

����isBadVersion(3)���õ�false

����isBadVersion(5)���õ�true

����isBadVersion(4)���õ�true

��ʱ���ǿ��Զ϶�4�ǵ�һ������İ汾��

*/

/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        if(n <= 0)
        {
            return 0;
        }//if
        
        int lhs =1, rhs = n;
        while(lhs <= rhs)
        {
            int mid = (lhs + rhs) / 2;
            if(SVNRepo::isBadVersion(mid))
            {
               if(mid == 1)
               {
                   return mid;
               }else if(mid > 1 && !SVNRepo::isBadVersion(mid-1))
               {
                   return mid;
               }else{
                    rhs = mid - 1;
               }//else
            }//if
            else{
                lhs = mid + 1;
            }//else
        }//while
        
        return -1;
    }
};
