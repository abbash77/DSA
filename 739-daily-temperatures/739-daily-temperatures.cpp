class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        s.push(0);
        int n=temperatures.size();
        vector<int> v(n);
        for(int i=n-1;i>=0;i--){
            int curr=temperatures[i];
            while(temperatures[s.top()]<=curr&&s.top()!=0){
                s.pop();
            }
            if(s.top()==0){
                v[i]=s.top();
            }
            else{
                v[i]=s.top()-i;
            }
            
            s.push(i);
        }
        return v;
    }
};