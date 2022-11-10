//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends


int findsmallerequal(int arr[],int n,int limit)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]<=limit)
            start=mid+1;
        else
            end=mid-1;
    }
    return start;
}
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int start=0,end=10000;
    while(start<=end)
    {
        int mid=(start+end)/2;
        int count=0;
        for(int i=0;i<n;i++)
        {
            count+=findsmallerequal(mat[i],n,mid);
        }
        if(count<k)
            start=mid+1;
        else
            end=mid-1;
    }
    return start;
}
