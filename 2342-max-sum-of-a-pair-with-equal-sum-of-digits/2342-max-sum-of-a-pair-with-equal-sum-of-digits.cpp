class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int s=0;
            while(a>0){
                s+=a%10;
                a=a/10;
            }
            m[s].push_back(nums[i]);
        }
        int maxi=-1;
        for(auto i:m){
            if(i.second.size()>1){
                sort(i.second.begin(),i.second.end());
            maxi=max(maxi,i.second[i.second.size()-1]+i.second[i.second.size()-2]);
                // for(int j=0;j<i.second.size();j++){
                //     for(int k=j+1;k<i.second.size();k++){
                //         int m=i.second[j]+i.second[k];
                //         maxi=max(maxi,m);
                    // }
                // }
            }
        }
        return maxi;
    }
};