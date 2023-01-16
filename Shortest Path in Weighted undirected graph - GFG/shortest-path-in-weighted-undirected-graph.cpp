//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
        dist[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        while(!pq.empty())
        {
            pair<int,int> curr=pq.top();
            pq.pop();
            int dis=curr.first;
            int node=curr.second;
            for(auto it:adj[node])
            {
                if(dist[node]+it.second<dist[it.first])
                {
                    dist[it.first]=dist[node]+it.second;
                    parent[it.first]=node;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        if(dist[n]==1e9)
        {
            return {-1};
        }
        vector<int> ans;
        int curr=n;
        ans.push_back(curr);
        while(parent[curr]!=curr)
        {
            curr=parent[curr];
            ans.push_back(curr);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends