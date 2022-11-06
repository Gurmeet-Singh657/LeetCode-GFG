class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1)
        {
            int n=s.length();
            string ans=s;
            string doublestring=s+s;
            for(int i=1;i<s.length();i++)
            {
                string curr=doublestring.substr(i,n);
                ans=min(ans,curr);
            }
            return ans;
        }
        sort(s.begin(),s.end());
        return s;
    }
};