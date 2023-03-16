//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char S[], int N)
{
    vector<vector<int>> dp(N,vector<int>(N,0)); 
    for(int i=1;i<=N;i++) // Traversing every length
    {
        for(int j=0;j<=N-i;j++)
        {
            if(i==1) dp[j][j]=1;
            else if(i==2) dp[j][j+1]=(S[j]==S[j+1]);
            else
            {
                int start=j;
                int end=j+i-1;
                if(S[start]==S[end])
                {
                    dp[start][end]=dp[start+1][end-1];
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(j-i+1>=2) ans+=dp[i][j];
        }
    }
            
    return ans;
}