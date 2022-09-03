class Solution {
public:
    bool f(string& s,string& p,int i,int j)
    {
        if(i==s.length())
        {
            if(j>=p.length()) return true;
            stack<char> st;
            for(int k=j;k<p.length();k++)
            {
                if(p[k]!='*')
                    st.push(p[k]);
                else
                {
                    if(st.empty())
                        return false;
                    st.pop();   
                }
            }
            return st.empty();
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