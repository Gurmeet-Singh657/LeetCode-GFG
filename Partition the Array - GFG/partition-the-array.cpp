//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    pair<long long,long long> solve(long long presum[],int start,int end)
    {
        int low=start,high=end-1;
        long long leftans=0,rightans=presum[end]-(start-1>=0?presum[start-1]:0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long leftsum=presum[mid]-(start-1>=0?presum[start-1]:0),rightsum=presum[end]-presum[mid];
            if(abs(leftsum-rightsum)<abs(leftans-rightans))
            {
                leftans=leftsum;
                rightans=rightsum;
            }
            if(leftsum<rightsum) low=mid+1;
            else high=mid-1;
        }
        return {leftans,rightans};
    }
    long long minDifference(int N, vector<int> &A) {
        long long presum[N]={0};
        for(int i=0;i<N;i++)
        {
            if(i>0) presum[i]+=presum[i-1];
            presum[i]+=A[i];
        }
        long long minans=1e9;
        for(int i=1;i<=N-3;i++)
        {
            auto fs=solve(presum,0,i);
            auto tf=solve(presum,i+1,N-1);
            long long first=fs.first;
            long long second=fs.second;
            long long third=tf.first;
            long long fourth=tf.second;
            long long maxi=max(max(first,second),max(third,fourth));
            long long mini=min(min(first,second),min(third,fourth));
            minans=min(minans,maxi-mini);
        }
        return minans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        long long ans = ob.minDifference(N, A);
        cout<<ans<<endl;
    }
    return 0;
} 
// } Driver Code Ends