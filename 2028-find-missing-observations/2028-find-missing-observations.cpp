class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int m=rolls.size();
        int total=mean*(n+m);
        int sum=0;
        for(int i=0;i<rolls.size();i++){
            sum+=rolls[i];
        }
        int diff=total-sum;
        if(diff<0){
            return {};
        }
        int val=diff/n;
        if(val==0){
            return {};
        }
        int rem=diff%n;
        if(val>6||val==6&&rem!=0){
            return {};
        }
        while(n--){
            ans.push_back(val);
        }
        for(int i=0;i<ans.size();i++){
            if(rem>0){
                ans[i]+=1;
                rem--;
            }
            else{
                break;
            }
            
        }
        
        return ans;
        
        
    }
};