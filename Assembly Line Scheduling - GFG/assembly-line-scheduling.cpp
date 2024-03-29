//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++



class Solution{
  public:
  int f(int j,int prev,vector<vector<int>>& a,vector<vector<int>>& T,vector<int>& x,vector<vector<int>>& dp)
  {
      if(j==a[0].size()) return x[prev];
      
      if(dp[j][prev+1]!=-1) return dp[j][prev+1];
      
      int firstLine=1e9,secondLine=1e9;
      
      if(prev!=1) firstLine=a[0][j]+f(j+1,0,a,T,x,dp);
      else firstLine=T[prev][j]+a[0][j]+f(j+1,0,a,T,x,dp);
      
      if(prev!=0) secondLine=a[1][j]+f(j+1,1,a,T,x,dp);
      else secondLine=T[prev][j]+a[1][j]+f(j+1,1,a,T,x,dp);
      
      return dp[j][prev+1]=min(firstLine,secondLine);
  }
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      int n=a[0].size();
      int prev0=x[0];
      int prev1=x[1];
      
      for(int j=n-1;j>=1;j--)
      {
          int curr0,curr1;
          for(int prev=0;prev<2;prev++)
          {
              int firstLine=1e9,secondLine=1e9;
          
              if(prev!=1) firstLine=a[0][j]+prev0;
              else firstLine=T[prev][j]+a[0][j]+prev0;
              
              if(prev!=0) secondLine=a[1][j]+prev1;
              else secondLine=T[prev][j]+a[1][j]+prev1;
              
              if(prev==0) curr0=min(firstLine,secondLine);
              else curr1=min(firstLine,secondLine);
          }
          prev0=curr0,prev1=curr1;
      }
      return min(e[0]+a[0][0]+prev0,e[1]+a[1][0]+prev1);
  }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends