class Solution {
public:
    void DFS(vector<vector<int>>& grid,int i,int j,queue<pair<int,int>>& q)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) return;
        
        grid[i][j]=-1;
        q.push({i,j});
        DFS(grid,i+1,j,q);
        DFS(grid,i-1,j,q);
        DFS(grid,i,j-1,q);
        DFS(grid,i,j+1,q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            int j=0;
            for(j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    DFS(grid,i,j,q);
                    break;
                }
            }
            if(j<grid[0].size())
                break;
        }
        // while(!q.empty())
        // {
        //     cout<<q.front().first<<" "<<q.front().second<<endl;
        //     q.pop();
        // }
        // for(int i=0;i<grid.size();i++)
        // {
        //     for(int j=0;j<grid[0].size();j++)
        //         cout<<grid[i][j]<<" ";
        //     cout<<endl;
        // }
        
        int level=0;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                auto it=q.front();
                q.pop();
                int i=it.first;
                int j=it.second;
                int indices[5]={0,-1,0,1,0};
                for(int k=0;k<4;k++)
                {
                    int curri=i+indices[k];
                    int currj=j+indices[k+1];
                    if(curri>=0 && currj>=0 && curri<grid.size() && currj<grid[0].size())
                    {
                        if(grid[curri][currj]==1)
                            return level;
                        else if(grid[curri][currj]==0)
                        {
                            grid[curri][currj]=-1;
                            q.push({curri,currj});
                        }
                    }
                        
                }
            }
            level++;
        }
        return level;
    }
};