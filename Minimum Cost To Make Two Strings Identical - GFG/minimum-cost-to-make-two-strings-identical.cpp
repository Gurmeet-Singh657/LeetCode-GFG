//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int f(int i,int j,string& X,string& Y,int costX,int costY,vector<vector<int>>& dp)
	{
	    if(i==X.length())
    	    return (Y.length()-j)*costY;
    	if(j==Y.length())
    	    return (X.length()-i)*costX;
    	if(dp[i][j]!=-1) return dp[i][j];
	    int ans;
	    if(X[i]==Y[j])
	        ans=f(i+1,j+1,X,Y,costX,costY,dp);
	    else
	        ans=min(costX+f(i+1,j,X,Y,costX,costY,dp),costY+f(i,j+1,X,Y,costX,costY,dp));
	    return dp[i][j]=ans;
	}
	int findMinCost(string X, string Y, int costX, int costY)
	{
	    int n=X.length(),m=Y.length();
	    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	    return f(0,0,X,Y,costX,costY,dp);
	}
  

};
	

//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;
        
       	int costX, costY;
       	cin >> costX >> costY;

        

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends