//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        int mini=1e9;
        int ans;
        for(auto it:mp)
        {
            int ele=it.first;
            int count=it.second;
            if(mini>count)
            {
                mini=count;
                ans=ele;
            }
            else if(mini==count)
            {
                ans=max(ans,ele);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends