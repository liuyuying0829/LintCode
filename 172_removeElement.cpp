/*
172 ɾ��Ԫ��

����һ�������һ��ֵ����ԭ��ɾ����ֵ��ͬ�����֣�����������ĳ��ȡ�

Ԫ�ص�˳����Ըı䣬���Ҷ��µ����鲻����Ӱ�졣

����
����һ������ [0,4,4,0,0,2,4,4]����ֵ 4

���� 4 ����4��Ԫ�ص�������Ϊ[0,0,0,2]
*/
class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        vector<int>::iterator beg = A.begin();
        int len = A.size();
        while(beg != A.end())
        {
            beg = find(A.begin(),A.end(),elem);
            if(beg != A.end())
            {
               A.erase(beg);
               --len;
            }//if
        }//while
        
        return len;
    }
};