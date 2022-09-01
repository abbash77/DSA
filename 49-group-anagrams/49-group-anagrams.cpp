class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v1;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string st=strs[i];
            sort(st.begin(),st.end());
            mp[st].push_back(strs[i]);
        }
        for(auto i:mp){
            v1.push_back(i.second);
        }
        return v1;
    }
};