class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(!st.empty()&&st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string s1="";
        while(!st.empty()){
            s1+=st.top();
            st.pop();
        }
        stack<char> st1;
        for(int i=0;i<s1.length();i++){
            st1.push(s1[i]);
            
        }
        string s2="";
        while(!st1.empty()){
            s2+=st1.top();
            st1.pop();
        }
        return s2;
        
        
        
    }
};