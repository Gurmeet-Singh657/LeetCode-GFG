//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> Dijkstra(int node,int n,vector<pair<int,int>> adj[])
    {
        vector<int> dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node});
        dist[node]=0;
        while(!pq.empty())
        {
            auto curr=pq.top();
            int cwt=curr.first,cnode=curr.second;
            pq.pop();
            for(auto it:adj[cnode])
            {
                int adj_node=it.first,adj_wt=it.second;
                if(dist[cnode]+adj_wt<dist[adj_node])
                {
                    dist[adj_node]=dist[cnode]+adj_wt;
                    pq.push({dist[adj_node],adj_node});
                }
            }
        }
        return dist;
    }
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int dthre) {
        vector<pair<int,int>> adj[n];
        for(auto it:edges)
        {
            int u=it[0],v=it[1],wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int city_Min=n+1;
        int city=-1;
        for(int i=0;i<n;i++) // for every edge, find shortest paths
        {
            vector<int> dist=Dijkstra(i,n,adj);
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(dist[j]<=dthre)
                {
                    count++;
                }
            }
            if(count<=city_Min) city_Min=count,city=i;
        }
        return city;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends