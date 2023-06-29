//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    int Even=0,Odd=0;
	    for(int i=0;i<s.length();i++)
	    {
	        if(i%2==0 && s[i]=='1') Even++;
	        if(i%2!=0 && s[i]=='1') Odd++;
	    }
	    // Even Even Even or Odd Odd Odd
	    Even%=3; 
	    Odd%=3;
	    // E
	    return Even==Odd;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends