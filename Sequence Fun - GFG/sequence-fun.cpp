//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    #define mod (int)(1e9)+7
	public:
		int NthTerm(int n){
		    long long currans=2;
		    if(n==1) return currans;
		    for(int i=2;i<=n;i++)
		    {
		        currans*=i;
		        currans%=mod;
		        currans+=1;
		        currans%=mod;
		    }
		    return currans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends