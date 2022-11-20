class Solution {
public:
    double dist(int x,int y){
        return pow(pow(x,2)+pow(y,2),0.5);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>> > pq;
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++){
            pq.push({dist(points[i][0],points[i][1]),{points[i][0],points[i][1]}});
        }
        for(int i=0;i<k;i++){
            if(!pq.empty()){
                auto j=pq.top();
                pq.pop();
                vector<int> a;
                a.push_back(j.second.first);
                a.push_back(j.second.second);
                ans.push_back(a);
            }
            
        }
        return ans;
    }
};