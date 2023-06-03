class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int> m;
        for(int i=0;i<items1.size();i++){
            m[items1[i][0]]+=items1[i][1];
        }
        for(int i=0;i<items2.size();i++){
            m[items2[i][0]]+=items2[i][1];
        }
        vector<vector<int>> ans;
        for(auto i:m){
            vector<int> a;
            a.push_back(i.first);
            a.push_back(i.second);
            ans.push_back(a);
        }
        return ans;
    }
};