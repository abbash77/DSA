class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]!='#'){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                
            }
        }
        string s1="";
        while(!st.empty()){
            s1+=st.top();
            st.pop();
        }
        stack<char> sst;
        for(int i=0;i<t.length();i++){
            if(t[i]!='#'){
                sst.push(t[i]);
            }
            else{
                 if(!sst.empty()){
                    sst.pop();
                }
            }
        }
         string s2="";
        while(!sst.empty()){
            s2+=sst.top();
            sst.pop();
        }
        if(s1==s2){
            return true;
        }
        else{
            return false;
        }
    }
};