class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int x=startPos[0];
        int y=startPos[1];
        vector<int> ans;
        
        for(int i=0;i<s.length();i++){
            int count=0;
            for(int j=i;j<s.length();j++){
                if(s[j]=='R'){
                    int k=y+1;
                    
                    if(k<0 || k>=n){
                        break;
                    }
                    else{
                         y++;
                        count++;
                    }
                   
                }
                else if(s[j]=='L'){
                     int k=y-1;
                    if(k<0 || k>=n){
                        break;
                    }
                    else{
                         y--;
                        count++;
                    }
                }
                else if(s[j]=='U'){
                     int k=x-1;
                    if(k<0 || k>=n){
                        break;
                    }
                    else{
                         x--;
                        count++;
                    }
                }
                else{
                     int k=x+1;
                    if(k<0 || k>=n){
                        break;
                    }
                    else{
                         x++;
                        count++;
                    }
                }
            }
            ans.push_back(count);
             x=startPos[0];
             y=startPos[1];
            
        }
        return ans;
    }
};











