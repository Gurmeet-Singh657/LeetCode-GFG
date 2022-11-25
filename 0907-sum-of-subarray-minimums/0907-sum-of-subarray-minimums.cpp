class Solution {
public:
    const int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i]))
            {
                int index=st.top();
                st.pop();
                int right=i-index-1;
                int left=index-(!st.empty()?st.top():-1)-1;
                ans=(ans+(long)arr[index]*(left+1)*(right+1))%mod;
            }
            st.push(i);
        }
        return ans;
        
    }
};