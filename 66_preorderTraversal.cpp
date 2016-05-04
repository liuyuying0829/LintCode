/*
 66 ��������ǰ�����

    ����
    �ʼ�
    ����
    ����

����һ�ö�������������ڵ�ֵ��ǰ�������
����һ�ö����� {1,#,2,3},

   1
    \
     2
    /
   3

 ���� [1,2,3].

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
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        if(root == NULL)
        {
            return vector<int>();
        }//if
        
        vector<int> ret;
        stack<TreeNode *> stk;
        stk.push(root);
        
        while(!stk.empty())
        {
            TreeNode *tmp = stk.top();
            ret.push_back(tmp->val);
            
            stk.pop();
            if(tmp->right != NULL)
                stk.push(tmp->right);
            if(tmp->left != NULL)
                stk.push(tmp->left);
        }//while
        
        return ret;
    }
};
