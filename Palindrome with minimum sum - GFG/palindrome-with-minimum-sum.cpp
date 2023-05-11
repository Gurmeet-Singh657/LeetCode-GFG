//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int i=0,j=s.length()-1;
        while(i<=j)
        {
            if(s[i]=='?' && s[j]=='?')
            {}
            else if(s[i]=='?')
            {
                s[i]=s[j];
            }
            else if(s[j]=='?')
            {
                s[j]=s[i];
            }
            else if(s[i]!=s[j])
            {
                return -1;
            }
            i++;
            j--;
        }
        int count=0;
        char prev='$';
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='?')
            {
                if(prev!='$')
                {
                    count+=abs(s[i]-prev);
                }
                prev=s[i];
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends