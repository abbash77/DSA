class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());
        int maxi=height[0];
        for(int i=0;i<height.size();i++){
            maxi=max(maxi,height[i]);
            prefix[i]=maxi;
        }
        maxi=height[height.size()-1];
        for(int i=height.size()-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            suffix[i]=maxi;
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=min(prefix[i],suffix[i])-height[i];
        }
        return ans;
    }
};