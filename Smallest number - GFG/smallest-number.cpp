//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        if(S>D*9) return "-1";
        
        string ans(D,'0');
        S--;
        for(int i=D-1;i>=1;i--)
        {
            int mini=min(9,S);
            S-=mini;
            ans[i]=(mini+'0');
        }
        S++;
        ans[0]=(S+'0');
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends