class Solution {
public:
    int numSplits(string s) {
        int count=0;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        unordered_set<char> st;
        for(int i=0;i<s.length();i++)
        {
            st.insert(s[i]);
            mp1[i]=st.size();
        }
        st.clear();
        for(int i=s.length()-1;i>=0;i--)
        {
            st.insert(s[i]);
            mp2[i]=st.size();
        }
        for(int i=1;i<s.length();i++)
        {
            int leftcnt=mp1[i-1];
            int rightcnt=mp2[i];
            if(leftcnt==rightcnt) count++;
        }
        return count;
    }
};