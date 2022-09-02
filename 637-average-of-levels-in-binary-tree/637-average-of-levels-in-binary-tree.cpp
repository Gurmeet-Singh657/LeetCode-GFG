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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> finalans;
        while(!q.empty())
        {
            double ans=0;
            int qsize=q.size();
            for(int i=0;i<qsize;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                ans+=((double)curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        
            ans/=qsize;
            finalans.push_back(ans);
        }
        return finalans;
    }
};