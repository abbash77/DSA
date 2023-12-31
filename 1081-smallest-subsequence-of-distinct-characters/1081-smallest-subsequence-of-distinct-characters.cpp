class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> mp;
        string ans = "";
        int vis[26] = {};
        int n = s.size();

        for(int i=0; i<n; ++i) mp[s[i]] = i;

        for(int i=0; i<n; ++i){
            if(vis[s[i] - 'a']++) continue;

            while(!ans.empty() and ans.back() > s[i] and i < mp[ans.back()]){
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            ans.push_back(s[i]);
        }
        return ans;
    }
};