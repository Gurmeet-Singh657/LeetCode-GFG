class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size=primes.size();
        vector<int> pointers(size,1);
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            long long mini=INT_MAX;
            for(int j=0;j<size;j++)
            {
                int factor=dp[pointers[j]];
                int ele=primes[j];
                mini=min(mini,ele*1LL*factor);
            }
            dp[i]=mini;
            for(int j=0;j<size;j++)
            {
                int factor=dp[pointers[j]];
                int ele=primes[j];
                if(factor*1LL*ele==mini)
                    pointers[j]++;
            }
        }
        return dp[n];
    }
};