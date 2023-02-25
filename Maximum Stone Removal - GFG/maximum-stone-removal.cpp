//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  class DisjointSet
    {
    public:
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow=0,maxCol=0;
        for(auto it:stones)
        {
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_set<int> st; // It stores those nodes which have stones
        for(auto it:stones)
        {
            int nodeRow=it[0];
            int nodeCol=it[1]+maxRow+1;
            ds.Union(nodeRow,nodeCol);
            st.insert(nodeRow);
            st.insert(nodeCol);
        }
        int count=0;
        for(auto it:st)
        {
            if(ds.findParent(it)==it) count++; 
        }
        return n-count;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends