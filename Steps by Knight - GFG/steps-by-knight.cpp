//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int dx[8]={-1,-1,1,1,2,2,-2,-2};
    int dy[8]={2,-2,2,-2,1,-1,1,-1};
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&K,vector<int>&T,int N)
	{
	    vector<vector<bool>> vis(N,vector<bool>(N,0));
	    int i=K[0]-1,j=K[1]-1;
	    int ti=T[0]-1,tj=T[1]-1;
	    queue<pair<int,int>> q;
	    q.push({i,j});
	    int steps=0;
	    while(!q.empty())
	    {
	        int qsize=q.size();
	        while(qsize--)
	        {
	            auto it=q.front();
	            q.pop();
	            int x=it.first,y=it.second;
	            if(x==ti && y==tj) return steps;
	            for(int k=0;k<8;k++)
	            {
	                int adjx=x+dx[k],adjy=y+dy[k];
	                if(adjx<0 || adjy<0 || adjx>=N || adjy>=N || vis[adjx][adjy]) continue;
	                q.push({adjx,adjy});
	                vis[adjx][adjy]=true;
	            }
	        }
	        steps++;
	    }
	    return steps;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends