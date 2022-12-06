//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int countfresh=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                countfresh++;
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
                int dx[4]={-1,0,1,0};
                int dy[4]={0,-1,0,1};
                for(int i=0;i<4;i++)
                {
                    int curri=it.first+dx[i];
                    int currj=it.second+dy[i];
                    if(curri>=0 && currj>=0 && curri<grid.size() && currj<grid[0].size() && grid[curri][currj]==1)
                    {
                        grid[curri][currj]=2;
                        q.push({curri,currj});
                    }
                }
            }
            countfresh-=q.size();
            time++;
        }
        return countfresh==0?time-1:-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends