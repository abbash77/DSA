class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> m;
        char ans;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                ans= s[i];
                break;
            }
            m[s[i]]=1;
        }
        return ans;
        
    }
   
};