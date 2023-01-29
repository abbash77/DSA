class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_map<int,bool> m;
      for(int i=0;i<nums.size();i++){
          m[nums[i]]=true;
      }
      int maxi=INT_MIN;
      for(int i=0;i<nums.size();i++){
          if(!m[nums[i]-1]){
              int cnt=0;
              int a=m[nums[i]];
              int j=0;
              while(m[nums[i]+j]){
                  cnt++;
                  j++;
              }
              maxi=max(cnt,maxi);
          }
      }
      return maxi;
    }
};