//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    class DisjointSet{
        vector<int> parent,rank,size;
        public:
        DisjointSet(int n)
        {
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++) parent[i]=i;
        }
        int findParent(int u)
        {
            if(parent[u]==u) return u;
            return parent[u]=findParent(parent[u]);
        }
        void Union(int u,int v)
        {
            u=findParent(u);
            v=findParent(v);
            if(size[u]<size[v])
            {
                parent[u]=v;
                size[v]+=size[u];
            }
            else
            {
                parent[v]=u;
                size[u]+=size[v];
            }
        }
    };
    int numProvinces(vector<vector<int>> adj, int V) {
      DisjointSet ds(V);
      for(int i=0;i<V;i++)
      {
          for(int j=i;j<V;j++)
          {
              if(adj[i][j]==1)
              {
                  if(ds.findParent(i)!=ds.findParent(j))
                  {
                      ds.Union(i,j);
                  }
              }
          }
      }
      int count=0;
      for(int i=0;i<V;i++)
      {
          if(ds.findParent(i)==i) count++;
      }
      return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends