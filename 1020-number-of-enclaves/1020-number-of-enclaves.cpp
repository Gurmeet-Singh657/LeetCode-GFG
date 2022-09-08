class Solution {
public:
    void DFS(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        grid[i][j]=0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int k=0;k<4;k++)
        {
            int curri=i+dx[k];
            int currj=j+dy[k];
            DFS(grid,curri,currj);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i*j==0 || i==grid.size()-1 || j==grid[0].size()-1)
                    DFS(grid,i,j);
            }
        }
        int count=0;
        for(int i=0;i<grid.size();i++)
            count+=accumulate(grid[i].begin(),grid[i].end(),0);
        return count;
    }
};