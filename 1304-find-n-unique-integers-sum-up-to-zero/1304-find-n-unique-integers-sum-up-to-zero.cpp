class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2!=0){
            int x=n/2;
            int y=-x;
            for(int i=0;i<x;i++){
                ans.push_back(y);
                y++;
            }
            ans.push_back(0);
            y++;
            for(int i=0;i<x;i++){
                ans.push_back(y);
                y++;
            }
            
        }
        else{
            int x=n/2;
            int y=-x;
            for(int i=0;i<x;i++){
                ans.push_back(y);
                y++;
            }
            y++;
            for(int i=0;i<x;i++){
                ans.push_back(y);
                y++;
            }
        }
        return ans;
    }
};