//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){  
        if(N*M==1) return 0;
        queue<pair<int,int>> q;
        q.push({x,y});
        int levels=0;
        int count=1;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        vector<vector<bool>> visited(N+1,vector<bool>(M+1,false));
        visited[x][y]=true;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                pair<int,int> it=q.front();
                q.pop();
                int i=it.first,j=it.second;
                for(int k=0;k<4;k++)
                {
                    int currx=i+dx[k],curry=j+dy[k];
                    if(currx>=1 && curry>=1 && currx<=N && curry<=M && !visited[currx][curry])
                    {
                        q.push({currx,curry});
                        visited[currx][curry]=true;
                        count++;
                    }
                }
            }
            levels++;
            if(count==N*M) return levels;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends