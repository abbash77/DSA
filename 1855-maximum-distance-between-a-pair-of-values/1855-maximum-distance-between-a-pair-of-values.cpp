class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0;;
        int j=0;
        int ans=0;
        while(j<nums2.size()&&i<nums1.size()){
            if(nums2[j]>=nums1[i]){
                ans=max(ans,j-i);
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return ans;
    }
};