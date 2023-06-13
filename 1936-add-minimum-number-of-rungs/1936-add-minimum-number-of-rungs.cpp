class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans=0;
        for(int i=0;i<rungs.size();i++){
            if(i==0){
                if(rungs[i]-0>dist){
                    ans+=(rungs[i]-1)/dist;  
                }
            }
            else{
               if(rungs[i]-rungs[i-1]>dist){
                    ans+=(rungs[i]-rungs[i-1]-1)/dist;  
                } 
            }
        }
        return ans;
    }
};