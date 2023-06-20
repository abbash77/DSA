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
        vector<vector<int>> ans;
        vector<int> v1;
        vector<int> v2;
        for(auto i:m){
            if(i.second==0){
                v1.push_back(i.first);
            }
            if(i.second==1){
                v2.push_back(i.first);
            }
            
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
        
    }
};