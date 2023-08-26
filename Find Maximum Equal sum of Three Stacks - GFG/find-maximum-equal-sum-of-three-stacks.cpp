//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2, vector<int> &S3)
    {
        for (int i = N1 - 2; i >= 0; i--)
            S1[i] += S1[i + 1];
        for (int i = N2 - 2; i >= 0; i--)
            S2[i] += S2[i + 1];
        for (int i = N3 - 2; i >= 0; i--)
            S3[i] += S3[i + 1];
        int i = 0, j = 0, k = 0;
        int count = 0;
        while (i < N1 && j < N2 && k < N3)
        {
            int maxi = max(S1[i], max(S2[j], S3[k]));
            if (maxi == S1[i])
            {
                i++;
            }
            if (maxi == S2[j])
            {
                j++;
            }
            if (maxi == S3[k])
            {
                k++;
            }
            if (S1[i] == S2[j] && S2[j] == S3[k])
            {
                return S1[i];
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends