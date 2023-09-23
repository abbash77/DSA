class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long sum = 0;
        for(auto b : beans) sum += b; // total number of beans
        
        long long minrem = LLONG_MAX; //maximum possible value in long long
        for(int i = 0; i < beans.size(); i++)
        {
            long long temp = sum;
            temp -= (beans.size() - i)*beans[i];
            if(minrem > temp) minrem = temp;
        }
        return minrem;
    }
};