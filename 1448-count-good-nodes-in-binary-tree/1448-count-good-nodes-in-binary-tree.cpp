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
    void goodNode(TreeNode* root,int maxi,int& count)
    {
        if(root==NULL)
            return;
        if(root->val>=maxi)
            count++;
        goodNode(root->left,max(maxi,root->val),count);
        goodNode(root->right,max(maxi,root->val),count);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int count=0;
        goodNode(root,root->val,count);
        return count;
    }
};