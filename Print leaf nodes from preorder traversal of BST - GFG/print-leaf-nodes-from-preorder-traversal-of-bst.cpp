//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findinorder(int start,int end,int inorder[],int ele)
    {
        for(int i=start;i<=end;i++)
        {
            if(inorder[i]==ele)
            return i;
        }
        return -1;
    }
    void BSTTraversal(int preorder[],int inorder[],int& ind,int start,int end,vector<int>& ans)
    {
        if(start>end)
        {
            // ans.push_back(inorder[start]);
            return;
        }
        if(start==end)
        {
            ans.push_back(inorder[start]);
        }
        int findind=findinorder(start,end,inorder,preorder[ind]);
        ind++;
        BSTTraversal(preorder,inorder,ind,start,findind-1,ans);
        BSTTraversal(preorder,inorder,ind,findind+1,end,ans);
    }
    vector<int> leafNodes(int arr[],int N) {
        int inorder[N];
        for(int i=0;i<N;i++)
        {
            inorder[i]=arr[i];
        }
        sort(inorder,inorder+N);
        vector<int> ans;
        int ind=0;
        BSTTraversal(arr,inorder,ind,0,N-1,ans);
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
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends