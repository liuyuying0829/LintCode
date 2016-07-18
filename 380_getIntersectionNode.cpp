/*
380 ��������Ľ���

��дһ�������ҵ������������ʼ�Ľ���ڵ㡣

 ע������

�����������û�н��棬����null��
�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
�ɼٶ���������ṹ��û��ѭ����
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }//if
        
        int lenA = 0, lenB = 0;
        ListNode *p = headA, *q = headB;
        while(p)
        {
            ++lenA;
            p = p->next;
        }//while
        
        while(q)
        {
            ++lenB;
            q = q->next;
        }//while
        
        if(lenA > lenB)
        {
            int i=0;
            p = headA;
            q = headB;
            while(i<lenA-lenB)
            {
                p = p->next;
                ++i;
            }//while
        }else{
            int j = 0;
            q = headB;
            p = headA;
            while(j < lenB - lenA)
            {
                q = q->next;
                ++j;
            }//while
        }//else
        
        while(p && q && p != q)
        {
            p = p->next;
            q = q->next;
        }//while
        
        return p;
    }
};