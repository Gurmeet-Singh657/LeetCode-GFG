//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    vector<int> count(nums.size(),0);
	    for(int i=0;i<nums.size()-1;i++)
	    {
	        for(int j=i+1;j<nums.size();j++)
	        {
	            if(nums[i]<nums[j])
	            {
	               count[i]++;
	            }
	            
	        }
	    }
	    int totalcount=0;
	    for(int i=0;i<nums.size();i++)
	    {
	        for(int j=i+1;j<nums.size()-1;j++)
	        {
	            if(nums[i]<nums[j])
	            totalcount+=count[j];
	        }
	    }
	    return totalcount;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends