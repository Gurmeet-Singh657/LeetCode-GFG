//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(source==destination) return 0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        q.push(source);
        dist[source.first][source.second]=0;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            int dr[4]={-1,1,0,0};
            int dc[4]={0,0,-1,1};
            for(int i=0;i<4;i++)
            {
                int currrow=row+dr[i];
                int currcol=col+dc[i];
                if(currrow>=0 && currcol>=0 && currrow<n && currcol<m && grid[currrow][currcol]==1 && dist[currrow][currcol]==INT_MAX)
                {
                    dist[currrow][currcol]=dist[row][col]+1;
                    if(currrow==destination.first && currcol==destination.second)
                    return dist[currrow][currcol];
                    q.push({currrow,currcol});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends