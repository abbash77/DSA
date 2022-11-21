class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char,int> m;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                m[s[i]]=i-m[s[i]]-1;
            }
            else{
                m[s[i]]=i;
            }
        }
        for(int i=0;i<26;i++){
            if(m.find(i+97)!=m.end()){
                if(distance[i]!=m[i+97]){
                    return false;
                }
            }
        }
        return true;
    }
};