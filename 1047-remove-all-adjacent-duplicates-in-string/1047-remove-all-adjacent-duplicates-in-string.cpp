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
        for(int i=0;i<s1.length()/2;i++){
            swap(s1[i],s1[s1.length()-1-i]);
        }
        return s1; 
    }
};