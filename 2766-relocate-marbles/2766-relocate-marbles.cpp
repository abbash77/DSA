class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int> m;
        for(auto it: nums) m[it]++;
        for(int x=0; x<moveTo.size(); x++)
        {
            m[moveFrom[x]]=0;
            m[moveTo[x]]++;
        }
        vector<int> ans;
        for(auto it: m)
        {
            if(it.second) ans.push_back(it.first);
        }
        return ans;
    }
};