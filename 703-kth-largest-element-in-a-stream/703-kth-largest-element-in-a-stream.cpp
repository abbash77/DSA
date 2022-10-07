class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int> > pq;
    int ka;
    KthLargest(int k, vector<int>& nums) {
        ka=k;
        int n=nums.size();
        for(int i=0;i<n&&i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            
            if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<ka){
                pq.push(val);
                if(pq.size()==ka){
                    return pq.top();
                }
        }
        if(!pq.empty()&&pq.top()<val){
                pq.pop();
                pq.push(val);
        }
        if(!pq.empty()){
            return pq.top();
        }
        return -1;
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */