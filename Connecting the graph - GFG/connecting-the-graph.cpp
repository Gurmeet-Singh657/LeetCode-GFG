//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    class DisjointSet
    {
        vector<int> parent, rank, size;
    
        public:
        DisjointSet(int n)
        {
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
        int findParent(int u)
        {
            if (parent[u] == u)
                return u;
            return parent[u] = findParent(parent[u]);
        }
        void Union(int u, int v)
        {
            u = findParent(u);
            v = findParent(v);
            if (size[u] < size[v])
            {
                parent[u] = v;
                size[v] += size[u];
            }
            else
            {
                parent[v] = u;
                size[u] += size[v];
            }
        }
    };
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int extra_Edges=0;
        for(auto it:edge)
        {
            int u=it[0],v=it[1];
            if(ds.findParent(u)!=ds.findParent(v))
            {
                ds.Union(u,v);
            }
            else
            {
                extra_Edges++;
            }
        }
        // counting number of disconnected components
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findParent(i)==i) count++;
        }
        count-=1;
        if(count>extra_Edges) return -1;
        return count;
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

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends