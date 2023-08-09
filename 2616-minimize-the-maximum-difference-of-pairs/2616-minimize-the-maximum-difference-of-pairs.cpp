class Solution {
public:
    bool helper(int mid, vector<int>& nums, int p){
        int ct = 0;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]-nums[i-1] <= mid){
                ct++;
                i++;
            }
        }
        
        return ct >= p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int st = 0, end = 1e9, mid, res;
        while(st <= end){
            mid = st + (end-st)/2;
            
            if(helper(mid, nums, p)){
                
                res = mid;
                end = mid-1;
            }
            else st = mid+1;
        }
        return res;
    
    }
};