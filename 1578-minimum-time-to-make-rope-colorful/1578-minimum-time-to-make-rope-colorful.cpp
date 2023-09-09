class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0;
        int j=1;
        int time=0;
        while(i<colors.length()&&j<colors.length()){
            if(colors[i]=='#'){
                i++;
                continue;
            }
            if(colors[i]==colors[j]){
                int minTime;
                if(neededTime[i]<neededTime[j]){
                    minTime=neededTime[i];
                    colors[i]='#';
                    i++;
                    j++;
                }
                else{
                    minTime=neededTime[j];
                    colors[j]='#';
                    j++;
                }
                time+=minTime;
            }
            else{
                i++;
                j++;
            }
        }
        return time;
        
    }
};