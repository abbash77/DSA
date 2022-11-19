class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int pair=0;
        int unpair=0;
        for(auto i:m){
            if(i.second%2==0){
                int a;
                a=i.second/2;
                pair+=a;
            }
            else{
                int a,b;
                if(i.second>1){
                    a=i.second/2;
                    pair+=a;
                }
                    unpair++;
            }
        }
        return {pair,unpair};
        
    }
};