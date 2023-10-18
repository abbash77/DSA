class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> left, star;
        int size = s.size();
        if (size % 2)
            return false;
        // the first pass 
        for (int i = 0; i < size; i++) {
            if (locked[i] == '0')   // unlocked '*'
                star.push(i);
            else if (s[i] == '(')   // locked '('
                left.push(i);
            else {                  // locked ')'
                if (!left.empty())
                    left.pop();
                else if (!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        // the second pass
        while (!left.empty()) {
            if (!star.empty() && star.top() > left.top()) {
                left.pop();
                star.pop();
            } else {
                return false;
            }
        }
        return true;
    }
};