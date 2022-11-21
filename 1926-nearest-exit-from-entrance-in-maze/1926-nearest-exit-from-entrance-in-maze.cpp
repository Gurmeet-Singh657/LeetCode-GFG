class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int steps=1;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                int dx[4]={-1,0,0,1};
                int dy[4]={0,-1,1,0};
                for(int i=0;i<4;i++)
                {
                    int curri=dx[i]+x;
                    int currj=dy[i]+y;
                    if(curri>=0 && currj>=0 && curri<maze.size() && currj<maze[0].size() && maze[curri][currj]=='.')
                    {
                        if(curri==0 || currj==0 || curri==maze.size()-1 || currj==maze[0].size()-1)
                        {
                            return steps;
                        }
                        maze[curri][currj]='+';
                        q.push({curri,currj});
                    }
                }    
            }
            steps++;
        }
        return -1;
    }
};