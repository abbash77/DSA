class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        vector<pair<int,int> > v;
        for(auto i:m){
            v.push_back({i.first,i.second});
        }
        sort(v.begin(),v.end(),cmp);
        int n=v.size();
        int i=0;
        while(k>0){
            v[i].second--;
            if(v[i].second==0){
                n--;
                i++;
            }
            k--;
        }
        return n;
        
    }
};