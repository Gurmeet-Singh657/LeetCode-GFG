//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int uppersum=0;
    Node* f(Node* root,int target,int sum)
    {
        if(root==NULL) return NULL;
        if(root->data==target)
        {
            uppersum=sum;
            return root;
        }
        if(root->data>target)
            return f(root->left,target,sum+root->data);
        if(root->data<target)
            return f(root->right,target,sum+root->data);
        return NULL;
    }
    
    void MinSum(Node* root,int& mini,int lowersum)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            lowersum+=root->data;
            mini=min(mini,lowersum);
        }
        MinSum(root->left,mini,lowersum+root->data);
        MinSum(root->right,mini,lowersum+root->data);
    }
    int maxDifferenceBST(Node *root,int target){
        // Finding the Target
        Node* tarRoot=f(root,target,0);
        if(!tarRoot) return -1;
        
        // Find the minimum difference
        int mini=1e9;
        MinSum(tarRoot,mini,0);
        mini-=target;
        return uppersum-mini;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends