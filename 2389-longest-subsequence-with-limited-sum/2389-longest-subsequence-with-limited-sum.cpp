class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int val=queries[i];
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(val-nums[j]>=0){
                    val-=nums[j];
                    cnt++;
                }
                else{
                    break;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};