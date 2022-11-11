//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string isSumOfTwo(int N){
        vector<bool> isprime(N+1,true);
        isprime[0]=isprime[1]=false;
        for(int i=2;i<=sqrt(N);i++)
        {
            if(isprime[i]==true)
            {
                for(int j=i*i;j<=N;j+=i)
                {
                    isprime[j]=false;
                }
            }
        }
        for(int i=2;i<=N/2;i++)
        {
            if(isprime[i] && isprime[N-i])
            return "Yes";
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends