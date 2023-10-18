class Solution {
public:
    int reverse(int val){
        int size=0;
        int v=val;
        while(v>0){
            int a=v%10;
            v=v/10;
            size++;
        }
        int i=size-1;
        v=val;
        int ans=0;
        while(v>0){
            int a=v%10;
            ans+=a*pow(10,i);
            i--;
            v=v/10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            s.insert(reverse(nums[i]));
        }
        return s.size();
    }
};