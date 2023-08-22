class RandomizedSet {
public:
    unordered_map<int,int>random;
    vector<int>to;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
         if(random.find(val)!=random.end())
        {
            return false;
        }
        
        to.push_back(val);
        random[val]=to.size()-1;
        return true;
    }
    
    bool remove(int val) {
          
        if(random.find(val)==random.end())
        {
            return false;
        }
        int last=to.back();
     to[random[val]]=to.back();
        to.pop_back();
        random[last]=random[val];
        random.erase(val);
        
        return true;
    }
    
    int getRandom() {
       int ran= rand()%to.size();
        return to[ran];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */