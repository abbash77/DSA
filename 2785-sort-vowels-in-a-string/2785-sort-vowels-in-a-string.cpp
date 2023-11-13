class Solution {
public:
     bool isVowel(char a){
        if(a=='A'||a=='E'||a=='I'||a=='O'||a=='U'||a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        vector<char> st;
        vector<int> loc;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                loc.push_back(i);
                st.push_back(s[i]);
            }
        }
        sort(st.begin(),st.end());
        for(int i=0;i<loc.size();i++){
            s[loc[i]]=st[i];
        }
        return s;
    }
};