class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++) hash[nums[i]]++;
        
        int count =0; 
        
        for(auto i: hash){
            if(k==0) {
                if(i.second>1) 
                    count++;
            }
             else {
                 if (hash.find(i.first - k) != hash.end()) 
                     count++;
             }
        }
        
        return count;
    }
};