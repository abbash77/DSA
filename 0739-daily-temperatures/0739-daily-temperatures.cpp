class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
          stack<int> st;
        vector<int> v(temperatures.size());
        vector<int> v1;
        st.push(-1);
       for(int i=temperatures.size()-1;i>=0;i--){
           int current=temperatures[i];
           while(st.top()!=-1 && current>=temperatures[st.top()]){
               st.pop();
           }
           v[i]=st.top();
           st.push(i);
           
       }
        for(int i=0;i<temperatures.size();i++){
            v1.push_back(v[i]-i);
        }
        for(int i=0;i<temperatures.size();i++){
            if(v1[i]<0){
                v1[i]=0;
            }
        }
        return v1;
    }
};