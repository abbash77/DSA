class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sumOfEven=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                sumOfEven+=nums[i];
            }
        }
        for(int i=0;i<queries.size();i++){
            if(nums[queries[i][1]]%2==0){
                sumOfEven-=nums[queries[i][1]];
            }
            nums[queries[i][1]]+=queries[i][0];
            if(nums[queries[i][1]]%2==0){
                sumOfEven+=nums[queries[i][1]];
            }
            ans.push_back(sumOfEven);
        }
        return ans;
    }
};