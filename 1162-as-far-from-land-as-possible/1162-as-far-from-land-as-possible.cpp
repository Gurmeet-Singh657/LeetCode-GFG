class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
                else if(grid[i][j]==0)
                    grid[i][j]=-1;
            }
        }
        int level=0;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                auto it=q.front();
                q.pop();
                int indices[5]={0,-1,0,1,0};
                for(int i=0;i<4;i++)
                {
                    int curri=it.first+indices[i];
                    int currj=it.second+indices[i+1];
                    if(curri>=0 && currj>=0 && curri<grid.size() && currj<grid[0].size() && grid[curri][currj]==-1)
                    {
                        grid[curri][currj]=0;
                        q.push({curri,currj});
                    }
                }
            }
            if(!q.empty())
                level++;
        }
        return level==0?-1:level;
    }
};