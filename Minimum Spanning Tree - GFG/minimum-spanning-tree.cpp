//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V,1e9),parent(V,-1);
        vector<bool> MST(V,false);
        key[0]=0;
        for(int i=1;i<=V-1;i++)
        {
            int mini=INT_MAX,node;
            for(int j=0;j<V;j++)
            {
                if(!MST[j] && key[j]<mini)
                {
                    mini=key[j];
                    node=j;
                }
            }
            MST[node]=true;
            for(auto it:adj[node])
            {
                int curr_node=it[0],curr_wt=it[1];
                if(!MST[curr_node] && key[curr_node]>curr_wt)
                {
                    key[curr_node]=curr_wt;
                    parent[curr_node]=node;
                }
            }
        }
        int sum=0;
        for(int i=0;i<V;i++)
        {
            sum+=key[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends