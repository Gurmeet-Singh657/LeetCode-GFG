//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    int partition(int arr[],int low,int high)
    {
        int i=low-1;
        int pivot=arr[high];
        for(int j=low;j<high;j++)
        {
            if(arr[j]<pivot)
            {
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return (i+1);
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        int low=l,high=r;
        int findk=k-1;
        while(low<=high)
        {
            int p=partition(arr,low,high);
            if(p==findk)
            return arr[p];
            else if(p<findk)
            {
                low=p+1;
            }
            else
            high=p-1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends