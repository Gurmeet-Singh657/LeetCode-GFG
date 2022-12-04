//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string S, int N)
    {
        vector<int> vowels(26,0);
        vector<int> consonants(26,0);
        int vow=0,cons=0;
        for(int i=0;i<N;i++)
        {
            if(S[i]=='a' || S[i]=='e' || S[i]=='i' || S[i]=='o' || S[i]=='u')
            {
                vowels[S[i]-'a']++;
                vow++;
            }
            else
            {
                consonants[S[i]-'a']++;
                cons++;
            }
        }
        if(vow==cons || vow==cons+1)
        {
            int ind=0;
            int v=0,c=0;
            while(ind<N)
            {
                while(v<26 && vowels[v]==0)
                    v++;
                if(ind<N)
                {
                    S[ind]=(char)(v+'a');
                    vowels[v]--;
                    ind++;
                }
                
                while(c<26 && consonants[c]==0)
                    c++;
                if(ind<N)
                {
                    S[ind]=(char)(c+'a');
                    consonants[c]--;
                    ind++;
                }
            }
            return S;
        }
        else if(cons==vow+1)
        {
            int ind=0;
            int v=0,c=0;
            while(ind<N)
            {
                while(c<26 && consonants[c]==0)
                    c++;
                if(ind<N)
                {
                    S[ind]=(char)(c+'a');
                    consonants[c]--;
                    ind++;
                }
                
                while(v<26 && vowels[v]==0)
                    v++;
                if(ind<N)
                {
                    S[ind]=(char)(v+'a');
                    vowels[v]--;
                    ind++;
                }
            }
            return S;
        }
        return "-1";
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends