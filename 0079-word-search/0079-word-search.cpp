class Solution {
public:
    bool checkword(bool visited[7][7],vector<vector<char>>& board,string word,int i,int j,int index)
    {
        if(index==word.size())
            return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j] || word[index]!=board[i][j])
            return false;
        int imover[4]={-1,0,0,1};
        int jmover[4]={0,-1,1,0};
        visited[i][j]=true;
        for(int k=0;k<4;k++)
        {
            
            if(checkword(visited,board,word,i+imover[k],j+jmover[k],index+1))
            {
                return true;
            }
        }
        visited[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         bool visited[7][7];
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                memset(visited,0,sizeof(visited));
                if(word[0]==board[i][j])
                {
                    if(checkword(visited,board,word,i,j,0))
                        return true;
                }
            }
        }
        
        return false;
    }
};