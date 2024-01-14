class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int> v(26 , 0) , v1(26 , 0);
        for(auto it : word1){
            v[it - 'a']++;
        }
        for(auto it : word2){
            v1[it - 'a']++;
        }
        sort(v.begin() , v.end());
        sort(v1.begin() , v1.end());
        reverse(v.begin() , v.end());
        reverse(v1.begin() , v1.end());
        if(set(word1.begin(),word1.end())!=
           set(word2.begin(),word2.end()))
            return false;
        for(int i = 0 ; i< 26 ; i++){
            if(v[i] != v1[i])return false;
        }
        return true;
    }
};