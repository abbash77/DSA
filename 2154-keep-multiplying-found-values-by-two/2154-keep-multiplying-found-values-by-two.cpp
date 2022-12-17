class Solution {
public:
    int findFinalValue(vector<int>& nums,int original) {
        unordered_map<int,bool> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=true;
        }
        while(true){
            if(m[original]){
                m[original]=false;
                original=2*original;
                // m[original]=true;
                
            }
            else{
                return original;
            }
        }
        return -1;
    }
};