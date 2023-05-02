//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
       unordered_map<string,int> mp;
       for(auto it:arr)
       {
           string rev=it;
           reverse(rev.begin(),rev.end());
           if(mp.find(rev)!=mp.end())
           {
               mp[rev]--;
               if(mp[rev]==0) mp.erase(rev);
           }
           else
           {
               mp[it]++;
           }
       }
       if(mp.size()==0) return true;
       if(mp.size()==1)
       {
           string curr=mp.begin()->first;
           string rev=curr;
           reverse(rev.begin(),rev.end());
           return rev==curr;
       }
       return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends