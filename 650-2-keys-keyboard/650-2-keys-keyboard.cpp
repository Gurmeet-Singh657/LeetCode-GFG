class Solution {
public:
    // Recursion
//     int f(int curr,int n,int count)
//     {
//         if(count==n)
//             return 0;
//         if(count>n)
//             return 1e9;
        
//         int firstway=1+f(curr,n,count+curr);
//         int secondway=2+f(count,n,count+count);
//         return min(firstway,secondway);
//     }
//     int minSteps(int n) {
//         if(n==0) return 0;
//         if(n==1) return 0;
//         return 1+f(1,n,1);
//     }
    
    // Memoization
    // int f(int curr,int n,int count,vector<vector<int>>& dp)
    // {
    //     if(count==n)
    //         return 0;
    //     if(count>n)
    //         return 1e9;
    //     if(dp[curr][count]!=-1) return dp[curr][count];
    //     int firstway=1+f(curr,n,count+curr,dp);
    //     int secondway=2+f(count,n,count+count,dp);
    //     return dp[curr][count]=min(firstway,secondway);
    // }
    // int minSteps(int n) {
    //     if(n==0) return 0;
    //     if(n==1) return 0;
    //     vector<vector<int>> dp(n+1,vector<int>(2*n+1,-1));
    //     return 1+f(1,n,1,dp);
    // }
    // Tabulation
    int minSteps(int n)
    {
        if(n==0 || n==1) return 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int count=n-1;count>=1;count--)
        {
            for(int curr=n-1;curr>=1;curr--)
            {
                    int firstway=(count+curr<=n?1+dp[curr][count+curr]:1e9);
                    int secondway=(count+count<=n?2+dp[count][2*count]:1e9);
                    dp[curr][count]=min(firstway,secondway);
            }
        }
      return 1+dp[1][1];  
    }
};