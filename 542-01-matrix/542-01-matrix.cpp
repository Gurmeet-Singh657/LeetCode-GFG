class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                {
                    mat[i][j]=-1; // suggesting that it is not visited
                }
                else if(mat[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
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
                    int curri=indices[k]+i;
                    int currj=indices[k+1]+j;
                    if(curri>=0 && currj>=0 && curri<mat.size() && currj<mat[0].size() && mat[curri][currj]<0)
                    {
                        mat[curri][currj]=1+mat[i][j];
                        q.push({curri,currj});
                    }
                        
                }
            }
        }
        return mat;
    }
};