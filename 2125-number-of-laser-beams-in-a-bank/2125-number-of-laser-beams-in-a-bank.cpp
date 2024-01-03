class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int prev=0;
        for(int i=0;i<bank.size();i++){
            int cnt=0;
            for(int j=0;j<bank[0].size();j++){
                if(bank[i][j]=='1'){
                    cnt++;
                }
            }
            
            if(i==0){
                
            }
            else if(cnt!=0){
                ans+=prev*cnt;
            }
            if(cnt!=0){
                prev=cnt;
            }
            
        }
        return ans;
    }
};