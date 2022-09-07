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
    void Preorder(TreeNode* root,string& ans)
    {
        if(root==NULL)
        return;
        ans+="(";
        ans+=to_string(root->val);
        Preorder(root->left,ans);
        if(root->left==NULL && root->right)
            ans+="()";
        Preorder(root->right,ans);
        ans+=")";
    }
    string tree2str(TreeNode* root) {
        if(root==NULL) return "";
        string ans="";
        Preorder(root,ans);
        return ans.substr(1,ans.length()-2);
    }
};