//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void DFS(int i,int j,vector<vector<char>>& mat,int n,int m,char symbol)
    {
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j]=='X' || mat[i][j]=='C') return;
        
        mat[i][j]=symbol;
        
        DFS(i+1,j,mat,n,m,symbol);
        DFS(i-1,j,mat,n,m,symbol);
        DFS(i,j+1,mat,n,m,symbol);
        DFS(i,j-1,mat,n,m,symbol);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0;i<n;i++)
        {
            DFS(i,0,mat,n,m,'C');
            DFS(i,m-1,mat,n,m,'C');
        }
        for(int j=0;j<m;j++)
        {
            DFS(0,j,mat,n,m,'C');
            DFS(n-1,j,mat,n,m,'C');
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                DFS(i,j,mat,n,m,'X');
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='C') mat[i][j]='O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends