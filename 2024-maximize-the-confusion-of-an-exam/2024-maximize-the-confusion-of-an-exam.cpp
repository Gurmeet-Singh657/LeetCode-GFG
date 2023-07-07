class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.length();
        int maxlen=0;
        // Calculating for True
        int i=0,j=0;
        int count=0;
        while(i<n)
        {
            if(answerKey[i]=='F') count++;
            while(j<=i && count>k)
            {
                if(answerKey[j]=='F') count--;
                j++;
            }
            maxlen=max(maxlen,i-j+1);
            i++;
        }
        // Calculating for False
        i=0,j=0;
        count=0;
        while(i<n)
        {
            if(answerKey[i]=='T') count++;
            while(j<=i && count>k)
            {
                if(answerKey[j]=='T') count--;
                j++;
            }
            maxlen=max(maxlen,i-j+1);
            i++;
        }
        return maxlen;
    }
};