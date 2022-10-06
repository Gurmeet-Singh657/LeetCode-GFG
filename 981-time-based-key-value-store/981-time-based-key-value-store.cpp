class TimeMap {
public:
    unordered_map<string,multiset<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({-timestamp,value});
    }
    
    string get(string key, int timestamp) {
        for(auto it:mp[key])
        {
            if((-it.first)<=timestamp)
            {
                return it.second;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */