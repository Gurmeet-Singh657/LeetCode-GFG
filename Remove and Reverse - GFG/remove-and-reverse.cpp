//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        int n=S.length();
        int i=0,j=n-1;
        vector<int> freq(26,0);
        for(auto it:S) freq[it-'a']++;
        vector<int> pos(26,-1);
        bool front=true;
        while(i<=j)
        {
            if(front==true)
            {
                int ele=S[i]-'a';
                if(freq[ele]>1) 
                    front=false;
                freq[ele]--;
                pos[ele]=i;
                i++;
            }
            else
            {
                int ele=S[j]-'a';
                pos[ele]=j;
                if(freq[ele]>1)
                    front=true;
                freq[ele]--;
                pos[ele]=j;
                j--;
            }
        }
        
        string str="";
        for(int i=0;i<n;i++)
        {
            int ele=S[i]-'a';
            if(pos[ele]==i) str.push_back(S[i]);
        }
        
        if(front==false) reverse(str.begin(),str.end());
        return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends