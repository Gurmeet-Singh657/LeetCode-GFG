class Solution {
public:
    string reorganizeString(string s) {
        int freq[26]={0};
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        int maxfreq=0;
        int freqchar='$';
        for(int i=0;i<26;i++)
        {
            if(maxfreq<freq[i])
            {
                freqchar=(char)(i+'a');
                maxfreq=freq[i];
            }
        }
        int n=s.length();
        if(maxfreq>(n+1)/2)
            return "";
        string ans(n,' ');
        int ind=0;
        while(maxfreq--)
        {
            ans[ind]=freqchar;
            ind+=2;
        }
        freq[freqchar-'a']=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            {
                int currfreq=freq[i];
                char ch=(char)(i+'a');
                while(currfreq--)
                {
                    ind=(ind>=n?1:ind);
                    ans[ind]=ch;
                    ind+=2;
                }
            }
        }
        return ans;
    }
};