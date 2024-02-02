class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long ans = -1, sum1 = 0, sum2 = 0, count1 = 0, count2 = 0;
    for(auto n: nums1) { sum1 += n; count1 += (n?0:1); }
    for(auto n: nums2) { sum2 += n; count2 += (n?0:1); }
    if(count1 != 0 && count2 != 0) ans = max(sum1 + count1, sum2 + count2);
    else if(count1 == 0 && count2 != 0 && (sum1 >= sum2 + count2) ) ans = sum1;
    else if(count2 == 0 && count1 != 0 && (sum2 >= sum1 + count1) ) ans = sum2;
    else if(count2 == 0 && count1 == 0 && sum1 == sum2) ans = sum1;
    return ans;
    }
};