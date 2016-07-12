/*
372 ��O(1)ʱ�临�Ӷ�ɾ������ڵ�

����һ���������е�һ���ȴ���ɾ���Ľڵ�(�Ǳ�ͷ���β)��������O(1)ʱ�临�Ӷ�ɾ��������ڵ㡣

����
���� 1->2->3->4���ͽڵ� 3��ɾ�� 3 ֮������Ӧ�ñ�Ϊ 1->2->4��
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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        if(node == NULL)
        {
            return ;
        }//if
        else if(node->next == NULL)
        {
            ListNode *p = node;
            node = NULL;
            
            delete p;
            p = NULL;
        }else{
            node->val = node->next->val;
            ListNode *p = node->next;
            node->next = p->next;
            
            delete p;
            p = NULL;
        }
    }
};