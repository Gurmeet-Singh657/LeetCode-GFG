//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    struct Node
    {
        Node* links[26];
        bool ContainsKey(char ch)
        {
            return links[ch-'a']!=NULL;
        }
        void set(char ch,Node* node)
        {
            links[ch-'a']=node;
        }
        Node* get(char ch)
        {
            return links[ch-'a'];
        }
    };
    class Trie
    {
        Node* root;
        public:
        Trie()
        {
            root=new Node();
        }
        void Insert(string& word)
        {
            Node* node=root;
            for(int i=0;i<word.length();i++)
            {
                if(!node->ContainsKey(word[i]))
                {
                    node->set(word[i],new Node());
                }
                node=node->get(word[i]);
            }
        }
        bool Search(string& word)
        {
            Node* node=root;
            for(int i=0;i<word.length();i++)
            {
                if(!node->ContainsKey(word[i]))
                {
                    return false;
                }
                node=node->get(word[i]);
            }
            return true;
        }
    };
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        Trie trie;
        for(auto it:s1)
        {
            trie.Insert(it);
            reverse(it.begin(),it.end());
            trie.Insert(it);
        }
        int count=0;
        for(auto it:s2)
        {
            string rev=it;
            reverse(rev.begin(),rev.end());
            if(trie.Search(it) || trie.Search(rev))
            {
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends