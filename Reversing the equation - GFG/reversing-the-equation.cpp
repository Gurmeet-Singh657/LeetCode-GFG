//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
    {
        string temp="";
        int i=s.length()-1;
        while(i>=0)
        {
            if(isdigit(s[i]))
            {
                int num=0;
                int pro=1;
                while(i>=0 && isdigit(s[i]))
                {
                    num=num+(s[i]-'0')*pro;
                    pro*=10;
                    i--;
                }
                temp+=to_string(num);
            }
            else
            {
                temp+=s[i];
                i--;
            }
        }
        return temp;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends