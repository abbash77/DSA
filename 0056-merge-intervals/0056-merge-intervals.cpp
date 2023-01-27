class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        pair<int,int> work;
        vector<vector<int>> ans;
        work={intervals[0][0],intervals[0][1]};
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<=work.second){
                work.second=max(work.second,intervals[i][1]);
            }
            else{
                vector<int> v{work.first,work.second};
                ans.push_back(v);
                work.first=intervals[i][0];
                work.second=intervals[i][1];
            }
        }
        vector<int> v{work.first,work.second};
        ans.push_back(v);
        
        return ans;
    }
};