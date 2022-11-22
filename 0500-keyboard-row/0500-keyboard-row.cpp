class Solution {
public:
    bool check(string w,unordered_map<char,int> &m1,unordered_map<char,int>& m2,unordered_map<char,int> &m3){
        int a=0;
        for(int i=0;i<w.length();i++){
            if(m1[w[i]]!=1){
                a=1;
                break;
            }
        }
        if(a==1){
            for(int i=0;i<w.length();i++){
                if(m2[w[i]]!=1){
                    a=2;
                    break;
                }
            }
        }
        if(a==2){
           for(int i=0;i<w.length();i++){
                if(m3[w[i]]!=1){
                    a=3;
                    break;
                }
            } 
        }
        if(a==3){
            return false;
        }
        else{
            return true;
        }
        
        
    }
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        unordered_map<char,int> m3;
        string a1="qwertyuiopQWERTYUIOP";
        string a2="asdfghjklASDFGHJKL";
        string a3="zxcvbnmZXCVBNM";
        for(int i=0;i<a1.length();i++){
            m1[a1[i]]=1;
        }
        for(int i=0;i<a2.length();i++){
            m2[a2[i]]=1;
        }
        for(int i=0;i<a3.length();i++){
            m3[a3[i]]=1;
        }
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            if(check(words[i],m1,m2,m3)){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};