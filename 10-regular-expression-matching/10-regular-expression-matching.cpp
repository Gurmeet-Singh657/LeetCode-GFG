class Solution {
public:
    bool f(string& s,string& p,int i,int j)
    {
        if(i==s.length())
        {
            if(j>=p.length()) return true;
            int countstar=0,countele=0;
            for(int k=p.length()-1;k>=j;k--)
            {
                if(p[k]=='*')
                    countstar++;
                else
                {
                    countele++;
                    if(countstar<countele)
                        return false;
                }
            }
            return true;
        }
        if(j>=p.length())
            return false;
        
        if(p[j+1]=='*')
        {
            if(s[i]==p[j] || p[j]=='.')
                return f(s,p,i+1,j) | f(s,p,i,j+2);
            else
                return f(s,p,i,j+2);
        }
        else if(s[i]==p[j] || p[j]=='.')
            return f(s,p,i+1,j+1);
        return false;
    }
    bool isMatch(string s, string p) {
        return f(s,p,0,0);
    }
};