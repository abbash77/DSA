class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            double a=(double)success/(double)spells[i];
            long long b=ceil(a);
            int j=lower_bound(potions.begin(),potions.end(),b)-potions.begin();
            ans.push_back(potions.size()-j);
        }
        return ans;
    }
};