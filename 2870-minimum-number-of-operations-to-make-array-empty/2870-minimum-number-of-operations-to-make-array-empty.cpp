class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> v;
        for(auto i:m){
            if(i.second==1){
                return -1;
            }
            v.push_back(i.second);
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]%3==0){
                ans+=v[i]/3;
            }
            else{
                ans+=(v[i]/3)+1;
            }
        }
        return ans;
    }
};