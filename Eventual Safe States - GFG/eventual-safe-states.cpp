//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool DFS(int node,vector<int> adj[],vector<bool>& vis,vector<bool>& dfsVis)
    {
        vis[node]=true;
        dfsVis[node]=true;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(DFS(it,adj,vis,dfsVis)) return true;
            }
            else if(dfsVis[it])
            return true;
        }
        dfsVis[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool> vis(V,0),dfsVis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                DFS(i,adj,vis,dfsVis);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(!dfsVis[i]) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends