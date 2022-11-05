class Solution {
public:
    struct Node{
        Node* ch[26];
        bool end;
        string word;
        Node()
        {
            for(int i=0;i<26;i++)
                ch[i]=NULL;
            end=false;
            word="";
        }
    };
    struct Trie
    {
        Node* root;
        Trie()
        {
            root=new Node();
        }
        void Insert(string& words)
        {
            Node* curr=root;
            for(int i=0;i<words.length();i++)
            {
                if(curr->ch[words[i]-'a']==NULL)
                {
                    curr->ch[words[i]-'a']=new Node();
                }
                curr=curr->ch[words[i]-'a'];
            }
            curr->word=words;
            curr->end=true;
        }
    };
    void searchword(int i,int j,vector<vector<char>>& board,Node* curr,unordered_set<string>& st,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m|| board[i][j]=='*' || curr->ch[board[i][j]-'a']==NULL )
            return;
        // cout<<board[i][j]<<endl;
        curr=curr->ch[board[i][j]-'a'];
        if(curr->end==true)
            st.insert(curr->word);
        // cout<<board[i][j]<<endl;
        char prevchar=board[i][j];
        board[i][j]='*';
        searchword(i+1,j,board,curr,st,n,m);
        searchword(i-1,j,board,curr,st,n,m);
        searchword(i,j+1,board,curr,st,n,m);
        searchword(i,j-1,board,curr,st,n,m);
        board[i][j]=prevchar;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        vector<string> ans;
        unordered_set<string> st;
        Trie trie;
        for(auto it:words)
        {
            trie.Insert(it);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                searchword(i,j,board,trie.root,st,n,m);
            }
        }
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};