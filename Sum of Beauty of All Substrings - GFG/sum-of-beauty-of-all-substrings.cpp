//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        int n=s.length();
        vector<vector<int>> v(26,vector<int>(n+1,0));
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a'][i+1]++;
        }
        for(int i=0;i<26;i++)
        {
            for(int j=1;j<=n;j++)
            {
                v[i][j]+=v[i][j-1];
            }
        }
        int totalsum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                int maxfreq=-1,minfreq=INT_MAX;
                for(int k=0;k<26;k++)
                {
                    int currfreq=v[k][j]-v[k][i-1];
                    if(currfreq!=0)
                    {
                        maxfreq=max(maxfreq,currfreq);
                        minfreq=min(minfreq,currfreq);    
                    }
                }
                totalsum+=(maxfreq-minfreq);
            }
        }
        return totalsum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends