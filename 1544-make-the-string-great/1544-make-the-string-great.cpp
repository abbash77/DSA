class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string str="";
        st.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(!st.empty()){
                if(st.top()-32==s[i] || st.top()+32==s[i]){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
         }
         if(st.empty()){
             return str;
         }
        else{
            while(!st.empty()){
            char top=st.top();
            str=str+top;
            st.pop();
            }
        }
        reverse(str.begin(),str.end());
        return str;
       
       
    }
};