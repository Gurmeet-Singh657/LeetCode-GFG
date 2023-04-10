//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        if(a>=b && a>=c)
        {
            int halfa=(a+1)/2;
            if(halfa-1<=b+c) return a+b+c;
        }
        if(b>=a && b>=c)
        {
            int halfb=(b+1)/2;
            if(halfb-1<=a+c) return a+b+c;
        }
        if(c>=a && c>=b)
        {
            int halfc=(c+1)/2;
            if(halfc-1<=a+b) return a+b+c;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends