class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0;
        string curr="";
        while(i<s.length())
        {
            if(s[i]==' ')
            {
                reverse(curr.begin(),curr.end());
                ans+=curr;
                curr="";
                ans+=' ';
            }
            else
            {
                curr+=s[i];
            }
            i++;
        }
        reverse(curr.begin(),curr.end());
        ans+=curr;
        curr="";
        return ans;
    }
};