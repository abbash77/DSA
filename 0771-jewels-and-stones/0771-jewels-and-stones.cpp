class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> m;
        
        for(int i=0;i<stones.size();i++){
            m[stones[i]]++;
        }
        int sum=0;
        for(int i=0;i<jewels.size();i++){
            sum+=m[jewels[i]];
        }
        return sum;
    }
};