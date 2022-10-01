class Solution {
public:
    int decode(vector<int> &dp,string s,int i){
        if(i==s.length()){
            return 1;
        }
        if(s[i]=='0'){
            return dp[i]=0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left=0,right=0;
        left=decode(dp,s,i+1);
        if(i+2<=s.length()){
            if(s[i]=='1'|| (s[i]=='2' && s[i+1]<='6')){
                right=decode(dp,s,i+2);
            }
        }
        
        return dp[i]=left+right;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
        return decode(dp,s,0);
        
    }
};