class Solution {
public:
    void f(vector<vector<int>>& grid,int matcher,int row,int col)
    {        
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]!=matcher)
            return;
        int dx[4]={-1,0,0,1};
        int dy[4]={0,-1,1,0}; 
        grid[row][col]=-matcher;
        for(int i=0;i<4;i++)
        {
            int curri=dx[i]+row;
            int currj=dy[i]+col;
            f(grid,matcher,curri,currj);
        } 
        // Why we are first colouring then discoloring
        // so that this node is not visited again -> we are coloring
        // but we should not consider if it has all direcn equal to matcher -> so discoloring is also neccessary
        if(row>0 && col>0 && row<grid.size()-1 && col<grid[0].size()-1 && abs(grid[row][col+1])==matcher && abs(grid[row][col-1])==matcher && abs(grid[row-1][col])==matcher && abs(grid[row+1][col])==matcher)
            grid[row][col]=matcher; 
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        f(grid,grid[row][col],row,col);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]<0)
                    grid[i][j]=color;
            }
        }
        return grid;
    }
};