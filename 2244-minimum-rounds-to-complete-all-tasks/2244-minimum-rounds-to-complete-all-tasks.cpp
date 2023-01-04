class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        int ans=0;
        for(auto i:m){
            int freq=i.second;
            if(freq == 1) return -1;
            ans += (freq % 3 == 0) ? freq/3 : freq/3 + 1;
            
        }
        return ans;
    }
};