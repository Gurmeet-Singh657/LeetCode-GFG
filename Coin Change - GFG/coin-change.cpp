//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    #define ll long long int
    long long int count(int coins[], int N, int sum) {
        vector<ll> ahead(sum+1,0);
        ahead[0]=1;
        for(int ind=N-1;ind>=0;ind--)
        {
            vector<ll> curr(sum+1,0);
            curr[0]=1;
            for(int s=1;s<=sum;s++)
            {
                long long nottake=ahead[s];
                long long take=0;
                if(s>=coins[ind])
                    take=curr[s-coins[ind]];
                curr[s]=take+nottake;
            }
            ahead=curr;
        }
        return ahead[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends