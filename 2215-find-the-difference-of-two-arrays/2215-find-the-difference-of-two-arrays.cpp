class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> m1;
        unordered_map<int,bool> m2;
        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]=true;
        }
        for(int i=0;i<nums2.size();i++){
            m2[nums2[i]]=true;
        }
        vector<vector<int>> ans;
        vector<int> dummy;
        for(int i=0;i<nums1.size();i++){
            if(!m2[nums1[i]]){
                dummy.push_back(nums1[i]);
                m2[nums1[i]]=true;
            }
        }
        ans.push_back(dummy);
        dummy.clear();
        for(int i=0;i<nums2.size();i++){
            if(!m1[nums2[i]]){
                dummy.push_back(nums2[i]);
                m1[nums2[i]]=true;
            }
        }
        ans.push_back(dummy);
        dummy.clear();
        return ans;
    }
};