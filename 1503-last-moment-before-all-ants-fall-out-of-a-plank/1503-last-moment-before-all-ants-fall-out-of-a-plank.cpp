class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        for (auto& pos : left) result = max(result, pos - 0);
        for (auto& pos : right) result = max(result, n - pos);
        return result;
    }
};