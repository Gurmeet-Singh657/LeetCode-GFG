class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int countfresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    countfresh++;
                }
            }
        }
        int time=0;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                auto it=q.front();
                q.pop();
                int i=it.first;
                int j=it.second;
                
                int indices[5]={0,1,0,-1,0};
                for(int k=0;k<4;k++)
                {
                    int curri=i+indices[k];
                    int currj=j+indices[k+1];
                    if(curri>=0 && currj>=0 && curri<grid.size() && currj<grid[0].size() && grid[curri][currj]==1)
                    {
                        countfresh--;
                        grid[curri][currj]=0;
                        q.push({curri,currj});
                    }
                }
            }
            if(!q.empty())
                time++;
        }
        return (countfresh==0)?time:-1;
    }
};