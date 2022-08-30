class Solution {
public:
    long long getsumof10(int n)
    {
        long long res=0;
        while(n)
        {
            res+=(int)(pow(10,n%10));
            n/=10;
        }
        return res;
    }
    bool reorderedPowerOf2(int n) {
        long long mainnumber=getsumof10(n);
        for(int i=0;i<32;i++)
        {
            if(mainnumber==getsumof10(1<<i))
                return true;
        }
        return false;
    }
};