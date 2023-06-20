class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> m;
        for(int i=0;i<matches.size();i++){
            m[matches[i][0]]=0;
            m[matches[i][1]]=0;
        }
        for(int i=0;i<matches.size();i++){
            m[matches[i][1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto i:m){
            if(i.second==0){
                ans[0].push_back(i.first);
            }
            if(i.second==1){
                ans[1].push_back(i.first);
            }
            
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
        
    }
};