class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k>0){
            int mini=pq.top();
            pq.pop();
            mini++;
            pq.push(mini);
            k--;
        }
        int mod=1e9+7;
        long long pro=1;
        while(!pq.empty()){
            pro=(pro*pq.top())%mod;
            pq.pop();
        }
        
        return pro%mod;
    }
};