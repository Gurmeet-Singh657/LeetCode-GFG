//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void DFS(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis,vector<pair<int,int>>& vec,int row0,int col0)
    {
        vis[i][j]=true;
        vec.push_back({i-row0,j-col0});
        for(int k=0;k<4;k++)
        {
            int curri=i+dx[k],currj=j+dy[k];
            if(curri<0 || currj<0 || curri>=grid.size() || currj>=grid[0].size() || vis[curri][currj] || grid[curri][currj]==0) continue;
            DFS(curri,currj,grid,vis,vec,row0,col0);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    vector<pair<int,int>> v;
                    DFS(i,j,grid,vis,v,i,j);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends