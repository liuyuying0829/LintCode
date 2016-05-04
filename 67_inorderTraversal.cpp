/*
67 ���������������

����һ�ö�����,�������������


���������� {1,#,2,3},

   1
    \
     2
    /
   3

���� [1,3,2].

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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    /*�ǵݹ�ʵ��*/
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        if(root == NULL)
        {
            return vector<int>();
        }//if
        
        vector<int> ret;
        stack<TreeNode *> stk;
        
        TreeNode *cur = root;
        while(!stk.empty() || cur != NULL)
        {
            if(cur != NULL)
            {
                stk.push(cur);
                cur = cur->left;
            }//if
            else{
                cur = stk.top();
                stk.pop();
                
                ret.push_back(cur->val);
                cur = cur->right;
            }//else
        }//while
        
        return ret;
    }
};