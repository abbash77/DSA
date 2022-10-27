class Solution {
public:
    bool fun(unordered_map<char,int> m,string word){
        for(int i=0;i<word.length();i++){
            if(m[word[i]]>0){
                m[word[i]]--;
            }
            else if(m[word[i]]<=0){
                return false;
            }
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> m;
        int c=0;
        for(int i=0;i<chars.size();i++){
            m[chars[i]]++;
        }
        for(int i=0;i<words.size();i++){
            if(fun(m,words[i])){
                c+=words[i].length();
            };
            
        }
        return c;
    }
};