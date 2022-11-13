class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber!=0)
        {
            int rem=columnNumber%26;
            if(rem==0)
            {
               ans+='Z';
               columnNumber/=26;
               columnNumber--;
            }
            else
            {
                char ch=(char)(rem-1+'A');
                ans+=ch;
                columnNumber/=26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};