class Solution {
public:
    bool isSubsequence(string s, string t) {
        int c=0,g=0;
        for(int i=0;i<s.length();i++){
            for(int j=0+g;j<t.length();j++){
                if(s[i]==t[j]){
                    g=j+1;
                    c++;
                    break;
                }
            }
        }
        if(s.length()==c){
            return true;
        }
        else{
            return false;
        }       

    }
};