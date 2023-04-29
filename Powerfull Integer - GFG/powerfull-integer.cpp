//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        map<int,int> mp;
        for(auto it:intervals)
        {
            int l=it[0],r=it[1];
            mp[l]++;
            mp[r+1]--;
        }
        int curr=0;
        int maxi=-1;
        bool flag=false; // candidate for maximum
        for(auto it:mp)
        {
            curr+=it.second; // prefixsum
            if(curr>=k) // prefixsum >=k
            {
                flag=true;
                maxi=it.first;
            }
            else if(flag==true) // prev element is the candidate
            {
                maxi=it.first-1;
                flag=false;
            }
            else
            {
                flag=false;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends