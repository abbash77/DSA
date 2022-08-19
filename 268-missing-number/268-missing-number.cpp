class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a;
        map<int,int> m;
        for(int i=0;i<=nums.size();i++){
            m[i]=0;
        }
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=1;
        }
        for(auto i:m){
            if(i.second==0){
                a=i.first;
            }
        }
        return a;
    }
};