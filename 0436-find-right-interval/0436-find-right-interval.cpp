class Solution {
public:
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        unordered_map<int,int> v;
        vector<int> v1;
        for(int i=0;i<intervals.size();i++){
            v[intervals[i][0]]=i;
            v1.push_back(intervals[i][0]);
        }
        vector<int> ans;
        sort(v1.begin(),v1.end());
        for(int i=0;i<intervals.size();i++){
            int index=lower_bound(v1.begin(),v1.end(),intervals[i][1])-v1.begin();
            if(index==v1.size()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(v[v1[index]]);
            }
            
        }
        return ans;
    }
};