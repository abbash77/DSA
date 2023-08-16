class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        int maxi=INT_MIN;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        for(int i=k;i<nums.size();i++){
            pq.push({nums[i],i});
            while(!pq.empty()){
                auto a=pq.top();
                if(i-a.second<k){
                    ans.push_back(a.first);
                    break;
                }
                else{
                    pq.pop();
                }
            }
        }
        return ans;
        
    }
};