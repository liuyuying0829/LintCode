/**
102 ��������

����һ�������ж����Ƿ��л���

������ʵ���������Ƿ�����������⣿ Yes
����
���� -21->10->4->5, tail connects to node index 1������ true
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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL)
        {
            return false;
        }//if
        
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
            {
                return true;
            }//if
        }//while

        return false;

    }
};


