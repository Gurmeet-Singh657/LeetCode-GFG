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
    void AddRow(int curr,TreeNode* root,int depth,int val)
    {
        if(root==NULL)
            return;
        if(curr+1==depth)
        {
            TreeNode* curr1=new TreeNode(val);
            TreeNode* curr2=new TreeNode(val);
            curr1->left=root->left;
            curr2->right=root->right;
            root->left=curr1;
            root->right=curr2;
            return;
        }
        AddRow(curr+1,root->left,depth,val);
        AddRow(curr+1,root->right,depth,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* curr=new TreeNode(val);
            curr->left=root;
            return curr;
        }
        AddRow(1,root,depth,val);
        return root;
    }
};