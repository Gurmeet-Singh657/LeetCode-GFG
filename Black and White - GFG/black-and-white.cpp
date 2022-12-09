//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends

#define mod (int)(1e9+7)
//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m)
{
    long long prod=n*m;
    prod%=mod;
    prod*=(prod-1);
    prod%=mod;
    long long sub1=0;
    if(n>=3 && m>=2)
        sub1=(4*1LL*(n-3+1)*1LL*(m-2+1))%mod;
    long long sub2=0;
    if(n>=2 && m>=3)
        sub2=(4*1LL*(n-2+1)*1LL*(m-3+1))%mod;
    prod-=sub1;
    prod-=sub2;
    return prod;
}