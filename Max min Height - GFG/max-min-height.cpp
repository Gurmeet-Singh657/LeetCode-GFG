//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        #define ll long long int
        bool check(ll mid,vector<int> a,int w,int k)
        {
            ll operations=0;
            int n=a.size();
            vector<int> prefix(n+1,0);
            for(int i=0;i<n;i++)
            {
                if(i!=0) prefix[i]+=prefix[i-1];
                int curr=prefix[i];
                if(a[i]+curr<mid)
                {
                    operations+=(mid-a[i]-curr);
                    prefix[i]+=(mid-a[i]-curr);
                    if(i+w<n) prefix[i+w]-=(mid-a[i]-curr);
                }
            }
            return operations<=k;
        }
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            ll maxi=*max_element(a.begin(),a.end());
            ll start=1,end=maxi+k;
            ll ans;
            while(start<=end)
            {
                ll mid=(start+end)/2;
                if(check(mid,a,w,k))
                {
                    ans=mid;
                    start=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends