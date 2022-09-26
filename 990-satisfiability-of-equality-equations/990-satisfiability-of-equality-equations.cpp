class Solution {
public:
    int parentfind(int u,vector<int>& parent)
    {
        if(parent[u]==u)
            return u;
        return parent[u]=parentfind(parent[u],parent);
    }
    bool equationsPossible(vector<string>& eq) {
       vector<int> parent(26);
        for(int i=0;i<26;i++) parent[i]=i;
       for(string e:eq)
        {
           if(e[1]=='=')
           {
               int u=parentfind(e[0]-'a',parent);
               int v=parentfind(e[3]-'a',parent);
               parent[u]=v;
           }
        }
        for(string e:eq)
        {
            if(e[1]=='!')
            {
                if(parentfind(e[0]-'a',parent)==parentfind(e[3]-'a',parent))
                    return false;
            }
        }
        return true;
    }
};