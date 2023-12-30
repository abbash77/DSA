class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        unordered_map<int,int> m;
        int evenVal=0;
        int oddVal=0;
        for(int i=0;i<position.size();i++){
            m[position[i]]++;
        }
        for(auto i:m){
            if(i.first%2==0){
                evenVal+=i.second;
            }
            else{
                oddVal+=i.second;
            }
        }
        return min(evenVal,oddVal);
        
        
    }
};