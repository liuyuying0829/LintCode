/**
103 �������� II

����һ��������������д��ڻ����򷵻ص������л�����ʼ�ڵ��ֵ�����û�л�������null��

������ʵ���������Ƿ�����������⣿ Yes
����
���� -21->10->4->5, tail connects to node index 1������10

*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if(head == NULL || head->next ==NULL)
        {
            return NULL;
        }//if
        
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                break;
            }//if
        }//while
        
        if(fast && fast == slow)
        {
            fast = head;
            while(fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }//while
            
            return fast;
        }//if
        return NULL;
        
    }
};


