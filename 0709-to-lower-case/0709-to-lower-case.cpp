class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++){
            if(65<=s[i]&&s[i]<91){
                s[i]=s[i]+32;
            }
        }
        return s;
    }
};