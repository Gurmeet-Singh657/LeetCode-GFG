//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    string binToGrey(string B) {
        string curr="";
        curr.push_back(B[0]);
        for(int i=1;i<B.length();i++)
        {
            if(B[i-1]==B[i]) curr.push_back('0');
            else curr.push_back('1');
        }
        return curr;
    }
    
    string greyToBin(string G) {
        string curr="";
        curr.push_back(G[0]);
        for(int i=1;i<G.length();i++)
        {
            if(G[i]==curr[i-1]) curr.push_back('0');
            else curr.push_back('1');
        }
        return curr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string B,G;
        
        cin>>B;
        cin>>G;

        Solution ob;
        cout << ob.binToGrey(B) << endl;
        cout << ob.greyToBin(G) << endl;
    }
    return 0;
}
// } Driver Code Ends