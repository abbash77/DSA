class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                 m[nums[i]]=0;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                m[nums[i]]++;
            }
        }
        int maxi=INT_MIN;
        for(auto i:m){
            maxi=max(maxi,i.second);
        }
        for(auto i:m){
            if(maxi==i.second){
                return i.first;
            }
        }
        return -1;
    }
};