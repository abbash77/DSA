class Solution {
public:
    char findTheDifference(string s, string t) {
        
     map<char,int> m;
        char a;
       
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            m[t[i]]++;
        }
        for(auto i:m){
            if(i.second%2!=0){
                 a=i.first;
            }
        }
        return a;
    }
};