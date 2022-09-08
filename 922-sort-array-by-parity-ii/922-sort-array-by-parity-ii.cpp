class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                v1.push_back(nums[i]);
            }
            else{
                v2.push_back(nums[i]);
            }
           
           
        }
        int c=0;
        int d=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                v.push_back(v1[c]);
                c++;
            }
            else{
                v.push_back(v2[d]);
                d++;
            }
        }
        return v;
       
    }
};

