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
    class BSTIterator
    {
        public:
        bool isreverse;
        stack<TreeNode*> st;
        BSTIterator(bool reverse,TreeNode* curr)
        {
            isreverse=reverse;
            push(curr);
        }
        void push(TreeNode* curr)
        {
            while(curr!=NULL)
            {
                st.push(curr);
                if(isreverse)
                    curr=curr->right;
                else
                    curr=curr->left;
            }
        }
        bool hasnext()
        {
            return !st.empty();
        }
        int next()
        {
            TreeNode* curr=st.top();
            st.pop();
            if(isreverse)
                push(curr->left);
            else
                push(curr->right);
            return curr->val;
        }
    };
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(false,root);
        BSTIterator r(true,root);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k)
                return true;
            else if(i+j<k)
                i=l.next();
            else
                j=r.next();
        }
        return false;
    }
};