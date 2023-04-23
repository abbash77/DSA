class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        int i, m = tasks.size(), count =0;
        for(i=0; i<m; i++)
        {
            mp[tasks[i]]++;
            count= max(count, mp[tasks[i]]); //find max frequency of task
        }
        int freq =0; //find no. of tasks with greatest frequency
        for(auto itr:mp)
        {
            if(itr.second==count)
                freq++;
        }
        return max(m, (1+n)*(count-1)+freq);
    }
};