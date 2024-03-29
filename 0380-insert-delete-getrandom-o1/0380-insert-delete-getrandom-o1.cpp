class RandomizedSet {
    unordered_map<int, int> m;
    vector<int> v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end()) return false;
        m[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()) return false;
        swap(v[m[val]], v[v.size()-1]);
        m[v[m[val]]]=m[val];
        v.pop_back();
        m.erase(val);
        return true;
        
    }
    
    int getRandom() {
        return v[rand()%(m.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */