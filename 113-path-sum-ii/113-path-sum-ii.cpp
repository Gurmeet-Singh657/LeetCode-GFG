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
    void findpathsum(TreeNode* root,int targetSum,vector<int> ans,vector<vector<int>>& finalans)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            if(targetSum==root->val)
            {
                ans.push_back(root->val);
                finalans.push_back(ans);
                ans.pop_back();
            }                
            return;
        }
        ans.push_back(root->val);
        findpathsum(root->left,targetSum-(root->val),ans,finalans);
        findpathsum(root->right,targetSum-(root->val),ans,finalans);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> finalans;
        vector<int> ans;
        findpathsum(root,targetSum,ans,finalans);
        return finalans;
    }
};