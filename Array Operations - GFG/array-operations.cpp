//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        int i=0;
        int count=0;
        while(i<n)
        {
            bool flag=false;
            while(i<n && arr[i]!=0)
            {
                flag=true;
                i++;
            }
            if(flag==true) // atleast one element is there
            {
                count++;
            }
            while(i<n && arr[i]==0)
            {
                i++;
            }
        }
        return count;
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends