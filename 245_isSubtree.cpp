/*
245 ����

��������ͬ��С�Ķ��������� T1 ���ϰ���Ľڵ㣻 T2 �кü��ٵĽڵ㡣
�����һ���㷨���ж� T2 �Ƿ�Ϊ T1��������

 ע������

�� T1 �д��ڴӽڵ� n ��ʼ�������� T2 ��ͬ�����ǳ� T2 �� T1 ��������
Ҳ����˵������� T1 �ڵ� n ���������ϣ����ϵĲ��ֽ��� T2 ��ȫ��ͬ��
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
         bool result  = false;
        if (T2 == nullptr) {
            return true;
        }
        if (T1 == nullptr) {
            return false;
        }
        // write your code here
        if (T1->val == T2->val) {
             result = dp(T1,T2);
        }
        if (!result) {
          result =  isSubtree(T1->left,T2);
        }
        if (!result) {
            result =  isSubtree(T1->right,T2);
        }
        return result;
    }
    
    bool dp(TreeNode *T1, TreeNode *T2) {
    
        if (T1 != nullptr && T2!=nullptr && T1->val == T2->val) {
            return dp(T1->left,T2->left) && dp (T1->right,T2->right);
        }
        if (T1 == nullptr && T2 == nullptr) {
            return true;
        }
        return false;
    }
};