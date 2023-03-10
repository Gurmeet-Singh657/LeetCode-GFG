class Solution {
public:
    struct Node{
        Node* links[26];
        int count=0;
        bool containsKey(char ch)
        {
            return links[ch-'a']!=NULL;
        }
        void setKey(char ch,Node* node)
        {
            links[ch-'a']=node;
        }
        Node* getKey(char ch)
        {
            return links[ch-'a'];
        }
    };
    
    class Trie{
        public:
        Node* root;
        Trie()
        {
            root=new Node();
        }
        void Insert(string& str)
        {
            Node* node=root;
            for(int i=0;i<str.length();i++)
            {
                if(!node->containsKey(str[i]))
                {
                    node->setKey(str[i],new Node());
                }
                node=node->getKey(str[i]);
                node->count++;
            }
        }
        int search(string& str)
        {
            Node* node=root;
            int ans=0;
            for(int i=0;i<str.length();i++)
            {
                if(!node->containsKey(str[i]))
                {
                    return ans;
                }
                node=node->getKey(str[i]);
                ans+=node->count;
            }
            return ans;
        }
        
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie trie;
        for(auto& it:words)
        {
            trie.Insert(it);
        }
        for(auto& it:words)
        {
            ans.push_back(trie.search(it));
        }
        return ans;
    }
};