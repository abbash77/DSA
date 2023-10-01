class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string st="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                v.push_back(st);
                st="";
                continue;
            }
            st+=s[i];
        }
        v.push_back(st);
        st="";
        for(int i=0;i<v.size();i++){
            reverse(v[i].begin(),v[i].end());
            st+=v[i]+' ';
        }
        st.pop_back();
        return st;
    }
};