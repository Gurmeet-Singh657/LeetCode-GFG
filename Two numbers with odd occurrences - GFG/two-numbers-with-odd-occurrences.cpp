//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    #define ll long long int
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        ll XorSum=0;
        for(ll i=0;i<N;i++)
        {
            XorSum^=Arr[i];
        }
        ll diffbit=XorSum&(~(XorSum-1));
        ll firstNum=0;
        for(ll i=0;i<N;i++)
        {
            if(diffbit&Arr[i]) firstNum^=Arr[i];
        }
        ll secondNum=firstNum^XorSum;
        return {max(firstNum,secondNum),min(firstNum,secondNum)};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends