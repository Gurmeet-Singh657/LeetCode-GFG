//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       int ans=0;
       bool flag=true;
       for(int i=x.length()-1;i>=0;i--)
       {
           int num=x[i]-'0'; // digit
           if(flag) ans=(ans+num)%11;
           else ans=(ans+num*10)%11;
           
           flag=!flag;
       }
       return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends