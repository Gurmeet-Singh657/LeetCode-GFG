class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0]) return k;
        int prev=arr[0]-1;
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1]) continue;
            if(prev+(arr[i]-arr[i-1]-1)>=k)
            {
                return k-prev+arr[i-1];
            }
            prev+=(arr[i]-arr[i-1]-1);
        }
        
        return k-prev+arr[n-1];
    }
};