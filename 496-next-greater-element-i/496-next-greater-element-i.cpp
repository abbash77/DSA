class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         stack<int> s;
        s.push(-1);
        int n=nums2.size();
        map<int,int> m;
        for(int i=n-1;i>=0;i--){
            int curr=nums2[i];
            while(s.top()<=curr&&s.top()!=-1){
                s.pop();
            }
            m[curr]=s.top();
            s.push(curr);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=m[nums1[i]];
        }
        return nums1;
    }
};