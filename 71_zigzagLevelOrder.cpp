/*
71 �������ľ���β�α���

����һ�ö�������������ڵ�ֵ�ľ���β�α���
���ȴ������ң���һ���ٴ������󣬲����֮�佻����У� 

����һ�ö����� {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

���������εĲ�α���Ϊ��

[
  [3],
  [20,9],
  [15,7]
]
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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
         if(root == NULL)
        {
            return vector<vector<int>>();
        }//if
        
        queue<TreeNode *> parent;
        parent.push(root);
        
        vector<vector<int>> ret;
        
        bool flag = true;
        while(!parent.empty())
        {
            vector<int> v;
            queue<TreeNode *> childs;
            
            while(!parent.empty())
            {
                TreeNode *tmp = parent.front();
                parent.pop();
                v.push_back(tmp->val);
                
                if(tmp->left != NULL)
                {
                    childs.push(tmp->left);
                }//if
                
                if(tmp->right != NULL)
                {
                    childs.push(tmp->right);
                }//if
            }//while
            if(flag)
            {
                ret.push_back(v);
                flag = !flag;
            }//if
            else{
                reverse(v.begin(),v.end());
                ret.push_back(v);
                flag = !flag;
            }
            parent = childs;
        }//while
        return ret;
    }
};