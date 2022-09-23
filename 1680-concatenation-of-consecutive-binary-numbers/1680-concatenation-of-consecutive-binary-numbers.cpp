class Solution {
    #define mod (int)(1e9+7)
public:
    int concatenatedBinary(int n) {
       long int ans=0;
       long long len=0;
       for(int i=1;i<=n;i++)
       {
           if((i&(i-1)) == 0) ++len;
           ans=((ans<<len)%mod+i)%mod;
       }
       return ans%mod;
    }
};