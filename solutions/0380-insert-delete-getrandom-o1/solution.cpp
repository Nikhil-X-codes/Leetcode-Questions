class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int,int> mp;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            arr.push_back(val);
            mp[val] = arr.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            int remove_index = mp[val];
            int last_element = arr.back();
            
            arr[remove_index] = last_element;

            mp[last_element] = remove_index;
            
            arr.pop_back();
            mp.erase(val);
            
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};
