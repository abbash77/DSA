class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> maxi;
        int sum1=0,sum2=0;
        for(int i=0;i<nums1.size();i++){
            sum1+=nums1[i];
        }
        for(int i=0;i<nums2.size();i++){
            sum2+=nums2[i];
        }
        if(sum1==sum2){
            return 0;
        }
        else if(sum1>sum2){
            for(int i=0;i<nums1.size();i++){
                maxi.push(nums1[i]-1);
            }
            for(int i=0;i<nums2.size();i++){
                maxi.push(6-nums2[i]);
            }
        }
        else{
            for(int i=0;i<nums1.size();i++){
                maxi.push(6-nums1[i]);
            }
            for(int i=0;i<nums2.size();i++){
                maxi.push(nums2[i]-1);
            }
        }
        int ans=0;
        int diff=abs(sum1-sum2);
        while(diff>0&&maxi.size()){
            int maxii=maxi.top();
            maxi.pop();
            diff-=min(diff,maxii);
            ans++;
        }
        if(diff>0){
            return -1;
        }
        return ans;
    }
};