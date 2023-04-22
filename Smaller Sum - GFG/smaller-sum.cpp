//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<long long> res;
        vector<int> v(arr);
        vector<long long> sum;
        long long s = 0;
        sort(v.begin(),v.end());
        for(int i=1;i<=n;i++){
            sum.push_back(s);
            s+=v[i-1];
        }
        for(int i=0;i<n;i++){
            int index = lower_bound(v.begin(),v.end(),arr[i])-v.begin();
            res.push_back(sum[index]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends