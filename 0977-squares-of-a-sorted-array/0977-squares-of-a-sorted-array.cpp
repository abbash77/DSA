class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int miniIndex=nums.size()-1;
        int miniVal=INT_MAX;
        // for(int i=0;i<nums.size();i++){
        //     if(0<=nums[i]){
        //         miniIndex=i;
        //         break;
        //     }
        // }
        for(int i=0;i<nums.size();i++){
            if(miniVal>abs(nums[i])){
                miniIndex=i;
                miniVal=abs(nums[i]);
            }
        }
        vector<int> ans;
        ans.push_back(nums[miniIndex]*nums[miniIndex]);
        int i=miniIndex-1;
        int j=miniIndex+1;
       
        while(i>=0&&j<nums.size()){
            if(abs(nums[i])<abs(nums[j])){
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
            else if(abs(nums[i])>abs(nums[j])){
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
            else {
                ans.push_back(nums[i]*nums[i]);
                ans.push_back(nums[j]*nums[j]);
                i--;
                j++;
            }
        }
        while(i>=0){
            ans.push_back(nums[i]*nums[i]);
            i--;
        }
        while(j<nums.size()){
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        return ans;
        
    }
};