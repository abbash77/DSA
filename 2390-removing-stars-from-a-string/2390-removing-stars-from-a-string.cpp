class Solution {
public:
    string removeStars(string s) {
         stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
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
        reverse(s1.begin(),s1.end());
        return s1;
    }
};