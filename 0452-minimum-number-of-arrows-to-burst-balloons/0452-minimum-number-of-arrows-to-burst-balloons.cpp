class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int s=points[0][0];
        int e=points[0][1];
        int n=points.size();
        for(int i=1;i<points.size();i++){
            if(s<=points[i][0]&&points[i][0]<=e){
                s=max(s,points[i][0]);
                e=min(e,points[i][1]);
                n--;
            }
            else{
                s=points[i][0];
                e=points[i][1];
            }
        }
        return n;  
    }
};