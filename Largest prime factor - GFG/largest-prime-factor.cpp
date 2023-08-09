//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        int i=2;
        int largest=1;
        while(i*i<=N)
        {
            if(N%i==0)
            {
                while(N%i==0)
                {
                    N/=i;
                }
                largest=i;
            }
            i++;
        }
        if(N>1) largest=N;
        return largest;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends