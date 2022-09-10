class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        unordered_map<int,int> m;
        for(int i=1;i<=n;i++){
            m[i]=0;
        }
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second==0){
                v.push_back(i.first);
            }
        }
        return v;
        
        
    }
};