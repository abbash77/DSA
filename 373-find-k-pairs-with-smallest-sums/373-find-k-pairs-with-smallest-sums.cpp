class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for(auto i:nums1){
            for(auto j:nums2){
                int sum=i+j;
                if(pq.size()<k){
                    pq.push({sum,{i,j}});
                }
                else if(pq.top().first>sum){
                    pq.pop();
                    pq.push({sum,{i,j}});
                }
                else{
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        vector<int> v;
        while(!pq.empty()){
            v.push_back(pq.top().second.first);
            v.push_back(pq.top().second.second);
            pq.pop();
            ans.push_back(v);
            v.clear();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};