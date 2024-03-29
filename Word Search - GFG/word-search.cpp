//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool DFS(int ind,string& word,int i,int j,vector<vector<char>>& board)
    {
        if(ind==word.length()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[ind]) return false;
        char prev=board[i][j];
        board[i][j]='$';
        if(DFS(ind+1,word,i+1,j,board)) return true;
        if(DFS(ind+1,word,i-1,j,board)) return true;
        if(DFS(ind+1,word,i,j+1,board)) return true;
        if(DFS(ind+1,word,i,j-1,board)) return true;
        board[i][j]=prev;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(word[0]==board[i][j])
                {
                    if(DFS(0,word,i,j,board))
                        return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends