/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int convert(TreeNode *root,int SUM)
    {
        if(root==NULL)return 0;
        else
        {
         int SUM1=convert(root->right,SUM);
            if(SUM1>SUM)
            {
                root->val=root->val+SUM1;
            }
            else
            {
                root->val=root->val+SUM;
            }
            SUM1=convert(root->left,root->val);
            if(SUM1>root->val)
            {
                return SUM1;
            }
            else
            {
                return root->val;
            }
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        convert(root,0);
        return root;
    }
};
