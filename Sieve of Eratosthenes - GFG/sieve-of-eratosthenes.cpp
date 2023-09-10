//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<bool> isPrime(N+1,1);// Assume all are prime numbers
        isPrime[0]=false;
        isPrime[1]=false;
        
        for(int i=2;i*i<=N;i++)
        {
            if(isPrime[i]) // if the current Number is prime
            {
                for(int j=2*i;j<=N;j+=i) // Mark all multiples as not Prime
                {
                    isPrime[j]=false;
                }
            }
        }
        
        vector<int> ans;
        for(int i=0;i<=N;i++)
        {
            if(isPrime[i]) ans.push_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends