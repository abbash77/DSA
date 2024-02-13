class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mapping;
        int i = 0;
        for (auto& num : target)
            mapping[num] = ++i;
        
        vector<int> A;
        for (int& num : arr)
            if (mapping.find(num) != mapping.end())
                A.push_back(mapping[num]);
        return target.size() - lengthOfLIS(A);
    }
private:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> piles;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(piles.begin(), piles.end(), nums[i]);
            if (it == piles.end())
                piles.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return piles.size();
}
};