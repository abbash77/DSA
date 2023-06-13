class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int ans=0;
        for(int i=1;i<intervals.size();i++){
            for(int j=i-1;j>=0;j--){
                if(intervals[j][0]<=intervals[i][0]&&intervals[j][1]>=intervals[i][1])                  {
                    ans++;
                    break;
                }
            }
        }
        return intervals.size()-ans;
    }
};