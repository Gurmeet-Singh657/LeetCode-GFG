//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    #define mod (int)(1e9 + 7)
    int sumOfNaturals(int n)
    {
        int first, second;
        if (n % 2 == 0)
        {
            first = n / 2;
            second = n + 1;
        }
        else
        {
            first = (n + 1) / 2;
            second = n;
        }
        return (first * 1LL * second) % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends