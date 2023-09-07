class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> m;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                m.clear();
                m[s[i]]++;
                cnt++;
            }
            else{
                m[s[i]]++;
            }
        }
        return cnt+1;
    }
};