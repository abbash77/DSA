class SeatManager {
public:
    
    priority_queue<int,vector<int>,greater<int>> pq;
    SeatManager(int n) {
        
        while(n>0){
            pq.push(n);
            n--;
        }
    }
    
    int reserve() {
        int val=pq.top();
        pq.pop();
        
        return val;
    }
    
    void unreserve(int seatNumber) {
       
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */