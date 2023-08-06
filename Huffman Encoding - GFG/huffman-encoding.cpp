//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    class Node
    {
        public:
        int data;
        char ch;
        Node* left;
        Node* right;
        Node(int d,char ch,Node* left,Node* right)
        {
            data=d;
            this->ch=ch;
            this->left=left;
            this->right=right;
        }
    };
    struct cmp
    {
        bool operator()(Node* a,Node* b)
        {
            return a->data>b->data;
        }
    };
    void PrintCode(Node* root,string curr,vector<string>& ans)
    {
        if(root==NULL) 
        {
            return;
        }
        if(root->ch!='$') ans.push_back(curr);
        PrintCode(root->left,curr+"0",ans);
        PrintCode(root->right,curr+"1",ans);
    }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*,vector<Node*>,cmp> pq;
		    for(int i=0;i<N;i++)
		    {
		        pq.push(new Node(f[i],S[i],NULL,NULL));
		    }
		    while(pq.size()>1)
		    {
		        auto it1=pq.top();
		        pq.pop();
		        auto it2=pq.top();
		        pq.pop();
		        pq.push(new Node(it1->data+it2->data,'$',it1,it2));
		    }
		    vector<string> ans;
		    PrintCode(pq.top(),"",ans);
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends