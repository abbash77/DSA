class Solution {
    int count(string &s, int k, char c) {
        int N = s.size(), cnt = 0, i = 0, ans = 0;
        for (int j = 0; j < N; ++j) {
            cnt += s[j] == c;
            while (cnt > k) cnt -= s[i++] == c; // if there are more than `k` `c` characters, shrink the window until the `cnt` drops back to `k`.
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
public:
    int maxConsecutiveAnswers(string s, int k) {
        return max(count(s, k, 'T'), count(s, k, 'F'));
    }
};