//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool minimumPlatform2(vector<int> &arr,vector<int> &dep,vector<int> &days,int platforms){
        vector<vector<int>> mp(101,vector<int>(2800,0));
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int day=days[i];
            int arrival=arr[i];
            int departure=dep[i];
            
            mp[day][arrival]++;
            mp[day][departure]--;
        }
        for(int day=1;day<=100;day++)
        {
            int curr_platforms=0;
            for(int ttime=0;ttime<2800;ttime++)
            {
                curr_platforms+=mp[day][ttime];
                if(curr_platforms>platforms) return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string p;
        getline(cin,p);
        string s;
        getline(cin,s);
        stringstream str(s);
        string ele;
        vector<int> arr;
        while(str >> ele){
            arr.push_back(stoi(ele));
        }
        int n=arr.size();
        vector<int> dep(n),days(n);
        for(int i=0;i<n;i++){
            cin>>dep[i];
        }
        for(int i=0;i<n;i++){
            cin>>days[i];
        }
        int platforms;
        cin>>platforms;
        Solution ob;
        if(ob.minimumPlatform2(arr,dep,days,platforms)){
            cout<<"True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }
    }
}
// } Driver Code Ends