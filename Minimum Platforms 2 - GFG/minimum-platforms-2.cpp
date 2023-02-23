//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool isPossible(vector<int>& arr,vector<int>& dep,int platforms)
    {
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int n=arr.size();
        int i=1,j=0;
        int curr=1;
        while(i<n && j<n)
        {
            if(arr[i]<dep[j])
            {
                curr++;
                i++;
            }
            else 
            {
                curr--;
                j++;
            }
            if(curr>platforms) return false;
        }
        return true;
    }
    bool minimumPlatform2(vector<int> &arr,vector<int> &dep,vector<int> &days,int platforms){
        unordered_map<int,vector<int>> arrival_map;
        unordered_map<int,vector<int>> departure_map;
        int n=arr.size();
        int mindays=100,maxdays=1;
        for(int i=0;i<n;i++)
        {
            arrival_map[days[i]].push_back(arr[i]);
            departure_map[days[i]].push_back(dep[i]);
            maxdays=max(maxdays,days[i]);
            mindays=min(mindays,days[i]);
        }
        for(int day=mindays;day<=maxdays;day++)
        {
            vector<int> arrmp=arrival_map[day];
            vector<int> depmp=departure_map[day];
            sort(arrmp.begin(),arrmp.end());
            sort(depmp.begin(),depmp.end());
            if(!isPossible(arrmp,depmp,platforms)) return false;
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