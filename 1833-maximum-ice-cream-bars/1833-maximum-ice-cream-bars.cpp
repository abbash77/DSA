class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<costs.size();i++){
            pq.push(costs[i]);
        }
        int ans=0;
        while(coins>0&&!pq.empty()){
            int t=pq.top();
            pq.pop();
            coins-=t;
            if(coins>=0){
                ans++;
            }
            
        }
        return ans;
    }
};