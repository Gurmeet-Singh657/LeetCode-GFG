class Solution {
public:
    bool valid(char num,vector<vector<char>>& board,int i,int j)
    {
        for(int k=0;k<9;k++)
        {
            if(i==k || board[k][j]=='.')
                continue;
            if(board[k][j]==num)
                return false;
        }
        for(int k=0;k<9;k++)
        {
            if(j==k || board[i][k]=='.')
                continue;
            if(board[i][k]==num)
                return false;
        }
        int row=3*(i/3);
        int col=3*(j/3);
        for(int k=row;k<row+3;k++)
        {
            for(int m=col;m<col+3;m++)
            {
                if(board[k][m]=='.')
                    continue;
                if(k==i && m==j) continue;
                if(board[k][m]==num)
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                char num=board[i][j];
                if(!valid(num,board,i,j))
                    return false;
            }
        }
        return true;
    }
};