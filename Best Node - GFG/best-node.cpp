//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        vector<bool> leafnode(N,1);
        for(int i=0;i<N;i++)
        {
            if(P[i]==-1) continue;
            P[i]-=1;
            leafnode[P[i]]=0;
        }
        long long maxi=-1e9;
        for(int i=0;i<N;i++)
        {
            if(leafnode[i])
            {
                int curr=i;
                long long num=0;
                while(curr!=-1)
                {
                    num=A[curr]-num;
                    maxi=max(maxi,num);
                    curr=P[curr];
                }
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends