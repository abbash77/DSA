class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        s.push(-1);
        for(int i=nums.size()-1;i>=0;i--){
            s.push(nums[i]);
        }
        int n=nums.size();
        vector<int> v(n);
        for(int i=n-1;i>=0;i--){
            int curr=nums[i];
            while(!s.empty()&&s.top()<=curr){
                s.pop();
            }
            if(s.empty()){
                v[i]=-1;
            }
            else{
                 v[i]=s.top();
            }
           
            s.push(curr);
        }
        return v;
    }
};