/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
       vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int qsize=q.size();
            vector<int> currans;
            while(qsize--)
            {
                Node* curr=q.front();
                q.pop();
                currans.push_back(curr->val);
                vector<Node*> myvec=curr->children;
                for(int i=0;i<myvec.size();i++)
                {
                    q.push(myvec[i]);
                }
            }
            ans.push_back(currans);
        }
        return ans;
    }
};