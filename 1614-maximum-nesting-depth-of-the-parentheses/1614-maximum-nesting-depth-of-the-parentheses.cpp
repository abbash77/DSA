class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                int a=st.size();
                maxi=max(maxi,a);
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                int a=st.size();
                maxi=max(maxi,a);
            }
        }
        return maxi;
    }
};