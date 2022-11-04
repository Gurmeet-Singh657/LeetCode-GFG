//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        int maxarea=0;
        int low=0,high=n-1;
        while(low<high)
        {
            int mini=min(height[low],height[high]);
            maxarea=max(maxarea,mini*(high-low-1));
            if(height[low]<=height[high])
            low++;
            else
            high--;
        }
        return maxarea;
    }   
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends