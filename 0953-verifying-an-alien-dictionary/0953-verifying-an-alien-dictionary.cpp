class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> m;
        for(int i=0;i<order.size();i++){
            m[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
            int j=0;
            int z=0;
            while(words[i][j]!='\0'&&words[i+1][j]!='\0'){
                if(m[words[i][j]]>m[words[i+1][j]]){
                    return false;
                }
                else if(m[words[i][j]]<m[words[i+1][j]]){
                    z=1;
                    break;
                }
                j++;
            }
            if(words[i][j]!='\0'&&z==0){
                return false;
            }
        }
        return true;
    }
};