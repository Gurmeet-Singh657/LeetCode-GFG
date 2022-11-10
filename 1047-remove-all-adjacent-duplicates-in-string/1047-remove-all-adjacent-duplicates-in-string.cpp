class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans="";
        for(int i=s.length()-1;i>=0;i--)
        {
            if(!st.empty() && s[i]==st.top())
                st.pop();
            else
                st.push(s[i]);
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};