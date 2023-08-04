//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        map<int,int> mp;
        unordered_map<int,int> PagesMapCounter;
        unordered_set<int> st;
        int counter=0;
        int PageFaults=0;
        for(int i=0;i<N;i++)
        {
            if(st.find(pages[i])!=st.end())
            {
                int num=PagesMapCounter[pages[i]];
                mp.erase(num);
                mp[++counter]=pages[i];
                PagesMapCounter[pages[i]]=counter;
                continue;
            }
            
            if(mp.size()<C)
            {
                mp[++counter]=pages[i];
                PagesMapCounter[pages[i]]=counter;
                st.insert(pages[i]);
            }
            else
            {
                auto it=mp.begin();
                st.erase(it->second);
                PagesMapCounter.erase(it->second);
                mp.erase(it);
                mp[++counter]=pages[i];
                PagesMapCounter[pages[i]]=counter;
                st.insert(pages[i]);
            }
            PageFaults++;
        }
        return PageFaults;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends