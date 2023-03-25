class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        pair<int,int> p;
        vector<int> v;
        vector<vector<int>> ans;
        p.first=intervals[0][0];
        p.second=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
             if(p.second>=intervals[i][0]){
                p.second=max(p.second,intervals[i][1]); 
             }
            else{
                v.push_back(p.first);
                v.push_back(p.second);
                ans.push_back(v);
                v.clear();
                p.first=intervals[i][0];
                p.second=intervals[i][1];
            }
        }
        v.push_back(p.first);
        v.push_back(p.second);
        ans.push_back(v);
        return ans;
    }
};