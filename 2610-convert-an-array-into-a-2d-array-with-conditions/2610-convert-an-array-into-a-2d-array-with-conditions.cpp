class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<vector<int>> v;
        while(true){
            int x=0;
            vector<int> v1;
            for(auto i:m){
                if(i.second>0){
                    x=1;
                    v1.push_back(i.first);
                    m[i.first]--;
                }
            }
            if(x==0){
                break;
            }
            v.push_back(v1);
        }
        return v;
        
    }
};