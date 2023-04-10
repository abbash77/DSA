class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        set<double> s;
        while(i<=j){
            double z=(double)(nums[i]+nums[j])/(double)2;
            s.insert(z);
            i++;
            j--;
        }
        return s.size();
    }
};