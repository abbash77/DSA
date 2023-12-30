class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenVal=0;
        int oddVal=0;
        for(int i=0;i<position.size();i++){
            if(position[i]%2==0){
                evenVal++;
            }
            else{
                oddVal++;
            }
        }
        return min(oddVal,evenVal);
        
        
    }
};