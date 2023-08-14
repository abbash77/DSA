class Solution {
public:
    int minSwaps(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='['){
                st.push(ch);
            }
            else{
                if(!st.empty()&&st.top()=='['){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        int a=0;
        int b=0;
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            if(ch=='['){
                a++;
            }
            else{
                b++;
            }
            
        }
        int ans=(a+1)/2+(b+1)/2;
        return ans/2;
    }
};