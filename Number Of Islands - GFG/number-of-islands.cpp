//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<int> ans;
        
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        int sizeofdis=n*m;
        DisjointSet ds(sizeofdis);
        int count=0;
        for(auto it:operators)
        {
            int row=it[0],col=it[1];
            if(visited[row][col])
            {
                ans.push_back(count);
                continue;
            }
            visited[row][col]=true;
            count++;
            int num1=row*m+col;
            for(int k=0;k<4;k++)
            {
                int crow=row+dx[k],ccol=col+dy[k];
                if(crow<0 || ccol<0 || crow>=n || ccol>=m || !visited[crow][ccol]) continue;
                int num2=crow*m+ccol;
                if(ds.findParent(num1)!=ds.findParent(num2))
                {
                    ds.Union(num1,num2);
                    count--;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends