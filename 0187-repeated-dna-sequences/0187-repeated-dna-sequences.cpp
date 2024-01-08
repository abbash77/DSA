class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10){
            return {};
        }
        unordered_map<string,int> m;
        vector<string> v;
        for(int i=0;i<=s.length()-10;i++){
            string val=s.substr(i,10);
            m[val]++;
        }
        for(auto i:m){
            if(i.second>1){
                v.push_back(i.first);
            }
        }
        return v;
    }
};