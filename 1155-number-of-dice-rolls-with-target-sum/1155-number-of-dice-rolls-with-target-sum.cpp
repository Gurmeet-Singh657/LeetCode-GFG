class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
  int dp[1001] = { 1 }, i, j, k;
  for (i = 1; i <= d; ++i)
    for (k = target; k >= (i == d ? target : 0); --k)
      for (j = k - 1, dp[k] = 0; j >= max(0, k - f); --j)
        dp[k] = (dp[k] + dp[j]) % 1000000007;
  return dp[target];
}
};