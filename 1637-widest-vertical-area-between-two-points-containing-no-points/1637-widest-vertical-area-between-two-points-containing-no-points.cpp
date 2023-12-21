class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int maxi=0;
        for(int i=0;i<points.size()-1;i++){
            int val=points[i+1][0]-points[i][0];
            maxi=max(maxi,val);
            
        }
        return maxi;
    }
};