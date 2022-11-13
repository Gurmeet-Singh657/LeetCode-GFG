//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#define mod (int)(1e9+7)
class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        sort(capacity.begin(),capacity.end());
        long long pro=capacity[0];
        for(int i=1;i<n;i++)
        {
            pro*=(capacity[i]-i);
            pro%=mod;
        }
        return pro;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends