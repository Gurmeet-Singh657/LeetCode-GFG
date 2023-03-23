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
        
        vector<int> pos(26,-1); // stores the latest position of the non repeating characters
        bool front=true; // string is reversed or not
        while(i<=j)
        {
            if(front==true)
            {
                int ele=S[i]-'a'; // a b c -- z -> 0 -- 25
                if(freq[ele]>1) // Whether character is repeating
                    front=false; // Reverse it
                if(freq[ele]==1) // Last character is left
                    pos[ele]=i;
                freq[ele]--;
                i++;
            }
            else
            {
                int ele=S[j]-'a';
                if(freq[ele]>1) 
                    front=true; // Reverse it
                if(freq[ele]==1) // Last character is left
                    pos[ele]=j;
                freq[ele]--;
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