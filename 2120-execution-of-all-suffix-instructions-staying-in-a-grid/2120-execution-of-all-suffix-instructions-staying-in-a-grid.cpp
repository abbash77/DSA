class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int mincol=0;
        int maxcol=n-1;
        int minrow=0;
        int maxrow=n-1;
        int savedinirow=startPos[0];
        int savedinicol=startPos[1];
        int inirow=startPos[0];
        int inicol=startPos[1];
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            int j=i;
            int k=0;
            inirow=savedinirow;
            inicol=savedinicol;
            while(true){
                if(j>=s.length()){
                    break;
                }
                if(s[j]=='R'){
                    if(inicol<maxcol){
                        inicol++;
                    }
                    else{
                        break;
                    }
                    
                }
                else if(s[j]=='L'){
                    if(inicol>mincol){
                        inicol--;
                    }
                    else{
                        break;
                    }
                    
                }
                else if(s[j]=='U'){
                    if(inirow>minrow){
                        inirow--;
                    }
                    else{
                        break;
                    }
                    
                }
                else if(s[j]=='D'){
                    if(inirow<maxrow){
                        inirow++;
                    }
                    else{
                        break;
                    }
                    
                }
                j++;
                k++;
                
            }
            ans.push_back(k);
        }
        return ans;
    }
};