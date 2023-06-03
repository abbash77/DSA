class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.first>b.first;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans=0;
        vector<pair<int,int> > v;
        for(int i=0;i<costs.size();i++){
            v.push_back({abs(costs[i][0]-costs[i][1]),i});
        }
        int n=costs.size()/2;
        int na=n;
        int nb=n;
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            int x=costs[v[i].second][0];
            int y=costs[v[i].second][1];
            if(x<=y&&na>0){
                ans+=x;
                na--;
            }
            else if(x>=y&&nb>0){
                ans+=y;
                nb--;
            }
            else if(x>=y&&nb==0){
                ans+=x;
                na--;

            }
            else if(x<=y&&na==0){
                ans+=y;
                nb--;
            }
        }
        
        return ans;
    }
};