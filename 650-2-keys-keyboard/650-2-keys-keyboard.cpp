class Solution {
public:
    int f(int curr,int n,int count)
    {
        if(count==n)
            return 0;
        if(count>n)
            return 1e9;
        
        int firstway=1+f(curr,n,count+curr);
        int secondway=2+f(count,n,count+count);
        return min(firstway,secondway);
    }
    int minSteps(int n) {
        if(n==0) return 0;
        if(n==1) return 0;
        return 1+f(1,n,1);
    }
};