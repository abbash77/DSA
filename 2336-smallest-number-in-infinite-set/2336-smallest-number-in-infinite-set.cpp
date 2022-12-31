class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_map<int,bool> m;
    SmallestInfiniteSet() {
        for(int i=1;i<1001;i++){
            pq.push(i);
            m[i]=true;
        }
    }
    
    int popSmallest() {
        int top=pq.top();
        pq.pop();
        m[top]=false;
        return top;
    }
    
    void addBack(int num) {
        if(!m[num]){
            pq.push(num);
            m[num]=true;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */