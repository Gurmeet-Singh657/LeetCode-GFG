//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> row(n,0);
        vector<int> col(n,0);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                row[i]+=matrix[i][j];
                col[j]+=matrix[i][j];
                maxi=max(maxi,row[i]);
                maxi=max(maxi,col[j]);
            }
        }
        int i=0,j=0;
        int ans=0;
        while(i<n && j<n)
        {
            int curr=max(row[i],col[j]);
            int diff=maxi-curr;
            ans+=diff;
            row[i]+=diff;
            col[j]+=diff;
            if(row[i]==maxi) i++;
            if(col[j]==maxi) j++;
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends