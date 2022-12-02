class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int x=0;
        int y=0;
        string ans="";
        while(true){
            if(x<word1.length()){
                ans+=word1[x];
                x++;
            }
            if(y<word2.length()){
                ans+=word2[y];
                y++;
            }
            if(x>=word1.length()&&y>=word2.length()){
                break;
            }
        }
        return ans;
    }
};