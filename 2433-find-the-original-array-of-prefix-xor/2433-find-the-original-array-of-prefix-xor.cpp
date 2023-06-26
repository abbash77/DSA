class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> v;
        v.push_back(pref[0]);
        int res=pref[0];
        for(int i=1;i<pref.size();i++){
            v.push_back(res^pref[i]);
            res=res^(res^pref[i]);
        }
        return v;
    }
};