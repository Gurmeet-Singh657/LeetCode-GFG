//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    class DisjointSet{
        public:
        vector<int> parent;
        vector<int> rank;
        
        DisjointSet(int n)
        {
            parent.resize(n+1);
            for(int i=1;i<=n;i++) parent[i]=i;
            rank.resize(n+1,0);
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
            if(rank[u]==rank[v])
            {
                rank[v]++;
                parent[u]=v;
            }
            else if(rank[u]>rank[v])
            {
                parent[v]=u;
            }
            else 
            {
                parent[u]=v;
            }
        }
    };
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
                                  vector<vector<int>> danger, int m) {
         DisjointSet ds(n);
         vector<string> ans;
         for(auto it:mix)
         {
             int sol1=ds.findParent(it[0]);
             int sol2=ds.findParent(it[1]);
             bool flag=false;
             for(int i=0;i<m;i++)
             {
                 int dsol1=ds.findParent(danger[i][0]);
                 int dsol2=ds.findParent(danger[i][1]);
                 if((dsol1==sol1 && dsol2==sol2) || (dsol1==sol2 && dsol2==sol1))
                 {
                     ans.push_back("No");
                     flag=true;
                     break;
                 }
             }
             if(flag==false) 
             {
                 ans.push_back("Yes");
                 ds.Union(sol1,sol2);
             }
         }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends