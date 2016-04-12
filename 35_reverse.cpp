/*
 35 ��ת����

��תһ������

����
����һ������1->2->3->null�������ת�������Ϊ3->2->1->null

��ս
��ԭ��һ�η�ת���
*/

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL)
        {
            return head;
        }//if
        
        /*����ͷ�巨��ת����*/
        ListNode *newHead = head;
        ListNode *p = head->next;
        newHead->next = NULL;
        while(p)
        {
            ListNode *r = p->next;
            p->next = newHead;
            newHead = p;
            
            p = r;
        }//while
        return newHead;
    }
};
