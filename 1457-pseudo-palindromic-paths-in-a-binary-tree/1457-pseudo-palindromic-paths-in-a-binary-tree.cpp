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
    int f(TreeNode* root,map<int,int>& mp)
    {
        mp[root->val]++;   
        if(root->left==NULL && root->right==NULL)
        {
            bool flag=false;
            for(auto it:mp)
            {
                if(flag==false && it.second%2!=0)
                    flag=true;
                else if(flag==true && it.second%2!=0)
                {
                    mp[root->val]--;
                    if(mp[root->val]==0) mp.erase(root->val);
                    return 0;
                }
            }
            mp[root->val]--;
            if(mp[root->val]==0) mp.erase(root->val);
            return 1;
        }
        
        int leftans=0;
        if(root->left)
            leftans=f(root->left,mp);
        int rightans=0;
        if(root->right)
            rightans=f(root->right,mp);
        mp[root->val]--;
        if(mp[root->val]==0)
            mp.erase(root->val);
        return leftans+rightans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL) return 0;
        map<int,int> mp;
        return f(root,mp);
    }
};