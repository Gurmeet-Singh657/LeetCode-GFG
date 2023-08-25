//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n=s.length();
        int start=0;
        unordered_map<char,int> mp;
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            while(mp.size()>k)
            {
                mp[s[start]]--;
                if(mp[s[start]]==0) mp.erase(s[start]);
                start++;
            }
            if(mp.size()==k)
                maxi=max(maxi,i-start+1);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends