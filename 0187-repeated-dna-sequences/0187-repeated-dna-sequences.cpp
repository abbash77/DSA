class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10){
            return {};
        }
        unordered_map<string,int> m;
        for(int i=0;s.length()-10>=0&&i<=s.length()-10;i++){
            string val=s.substr(i,10);
            m[val]++;
        }
        vector<string> ans;
        for(auto val:m){
            if(val.second>1){
                ans.push_back(val.first);
            }
        }
        return ans;
    }
};