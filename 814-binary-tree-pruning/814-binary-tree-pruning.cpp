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
    int f(TreeNode* root)
    {
        if(root==NULL)
            return 0;
       int leftr=f(root->left);
       int rightr=f(root->right);
       if(leftr==1 && rightr==1) //that means 1 is present at back at both ends
           return 1;
        else if(leftr==1)
        {
            root->right=NULL;
            return 1;
        }
        else if(rightr==1)
        {
            root->left=NULL;
            return 1;
        }
        // when both of them are 0
        root->left=NULL;
        root->right=NULL;
        if(root->val==1)
            return 1;
        return 0;
    }
    TreeNode* pruneTree(TreeNode* root) {
        int val=f(root);
        if(val==1)
            return root;
        return NULL;
    }
};