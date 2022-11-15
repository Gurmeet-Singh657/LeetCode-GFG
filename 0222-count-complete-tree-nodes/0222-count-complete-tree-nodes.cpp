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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lefttr=0;
        TreeNode* rootleft=root;
        while(rootleft!=NULL)
        {
            rootleft=rootleft->left;
            lefttr++;
        }
        int rightr=0;
        TreeNode* rootright=root;
        while(rootright!=NULL)
        {
            rootright=rootright->right;
            rightr++;
        }
        if(lefttr==rightr)
            return (int)pow(2,lefttr)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};