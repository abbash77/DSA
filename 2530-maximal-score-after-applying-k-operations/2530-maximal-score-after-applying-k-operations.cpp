class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        long long ans=0;
        while(!pq.empty()){
            long long top=pq.top();
            pq.pop();
            long long com=0;
            ans+=top;
            if(top%3==0){
                com=1;
            }
            long long val=top/3;
            if(!com){
                val++;
            }
            pq.push(val);
            k--;
            if(k==0){
                break;
            }
        }
        return ans;
    }
};