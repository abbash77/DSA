class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue <int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int a=pq.top();
        pq.pop();
        return (pq.top()-1)*(a-1);
    }
};