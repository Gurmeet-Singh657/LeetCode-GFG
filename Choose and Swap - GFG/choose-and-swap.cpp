//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        set<char> st(a.begin(),a.end());
        char ch1='$',ch2;
        for(int i=0;i<a.length();i++)
        {
            for(auto it:st)
            {
                if(it<a[i])
                {
                    ch1=a[i];
                    ch2=it;
                    break;
                }
            }
            st.erase(a[i]);
            if(ch1!='$') break;
        }
        if(ch1=='$') return a;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]==ch1) a[i]=ch2;
            else if(a[i]==ch2) a[i]=ch1;
        }
        return a;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends