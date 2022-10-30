class Solution {
public:
    // if some path is smaller and it is lost due to no. of 1s exceeded
    // but we have marked that visited
    // it is wrong
    // so I should take such that every visited path should be different in itself
    int shortestPath(vector<vector<int>>& grid, int k) {
        // vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<vector<int>>> visited(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,0)));
        queue<vector<int>> q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({0,0,0,k});
        // visited[0][0]=true;
        visited[0][0][k]=true;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int i=it[0];
            int j=it[1];
            int steps=it[2];
            int left=it[3];
            // cout<<grid[i][j]<<endl;
            if(i==n-1 && j==m-1) return steps;
            for(int ind=0;ind<4;ind++)
            {
                int curri=dx[ind]+i;
                int currj=dy[ind]+j;
                if(curri>=0 && currj>=0 && curri<n && currj<m && !visited[curri][currj][left])
                {
                    if(grid[curri][currj]==1)
                    {
                        if(left>0)
                        {
                            // visited[curri][currj]=1;
                            visited[curri][currj][left]=1;
                            q.push({curri,currj,steps+1,left-1});
                        }
                    }
                    else
                    {
                        visited[curri][currj][left]=1;
                        q.push({curri,currj,steps+1,left});
                    }
                }
            }
        }
        return -1;
    }
};