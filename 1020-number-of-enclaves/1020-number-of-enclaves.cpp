class Solution {
public:
    void reachborder(vector<vector<int>>& grid,int i,int j,int& count)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        
        if(i==grid.size()-1 || i==0 || j==0 || j==grid[0].size()-1)
            count=-1;
        else if(count>=0)
            count++;
        grid[i][j]=0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int k=0;k<4;k++)
        {
            int curri=i+dx[k];
            int currj=j+dy[k];
            reachborder(grid,curri,currj,count);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int curr=0;
                    reachborder(grid,i,j,curr);
                    if(curr>0)
                        count+=curr;
                }
            }
        }
        return count;
    }
};