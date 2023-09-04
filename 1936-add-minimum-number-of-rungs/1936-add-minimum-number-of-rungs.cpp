class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int prev=0;
        int count=0;
        for(int i=0;i<rungs.size();i++){
            if(rungs[i]-prev<=dist){
                prev=rungs[i];
            }
            else{
                if((rungs[i]-prev)% dist==0){
                    count+=((rungs[i]-prev)/dist)-1;
                    prev=rungs[i];
                }
                else{
                    count+=(rungs[i]-prev)/dist;
                    prev=rungs[i];
                }
            }
        }
        return count;
    }
};