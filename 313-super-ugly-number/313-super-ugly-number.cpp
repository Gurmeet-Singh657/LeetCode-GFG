class Solution {
public:
     class triple{
     public:
      long long int value;
      int primeno;
      int pointer;
     };
    struct cmp {
        bool operator()(triple const& t1, triple const& t2)
        {
            return t1.value>t2.value;
        }
    };
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size=primes.size();
        priority_queue<triple,vector<triple>,cmp> pq;
        for(int j=0;j<size;j++)
        {
            pq.push({primes[j],primes[j],1});
        }
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            auto it=pq.top();
            pq.pop();
            long long mini=it.value;
            dp[i]=mini;
            pq.push({it.primeno*1LL*dp[it.pointer+1],it.primeno,it.pointer+1});
            while(pq.top().value==mini)
            {
                auto it=pq.top();
                pq.pop();
                pq.push({it.primeno*1LL*dp[it.pointer+1],it.primeno,it.pointer+1});
            }
        }
        return dp[n];
    }
};