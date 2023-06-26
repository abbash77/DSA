class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++){
            int m=arr[i];
            int cnt=0;
            while(m>0){
                m=m&(m-1);
                cnt++;
            }
            v.push_back({cnt,arr[i]});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};