class RandomizedSet {
public:
    
    // mp has num val as key and index of val in arr as value
    
    unordered_map<int, int> mp;
    
    // store the val in array, for finding random number in O(1)
    
    vector<int> arr;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val))
            return false;
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val))
        {
            int idx = mp[val];
            int last_val = arr.back();
            arr[idx] = last_val;
            arr.pop_back();
            mp[last_val] = idx;
            mp.erase(val);  
            return true;
        } 
        return false;
    }
    
    int getRandom() { 
        int rand_idx = rand() % arr.size();
        return arr[rand_idx];
    }
};