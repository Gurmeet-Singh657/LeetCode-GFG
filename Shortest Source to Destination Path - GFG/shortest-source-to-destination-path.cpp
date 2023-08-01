//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0]==0) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        A[0][0]=0;
        int steps=0;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                auto it=q.front();
                q.pop();
                int x=it.first,y=it.second;
                if(x==X && y==Y) return steps;
                for(int k=0;k<4;k++)
                {
                    int adjx=x+dx[k],adjy=y+dy[k];
                    if(adjx>=0 && adjy>=0 && adjx<N && adjy<M && A[adjx][adjy]==1)
                    {
                        q.push({adjx,adjy});
                        A[adjx][adjy]=0;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends