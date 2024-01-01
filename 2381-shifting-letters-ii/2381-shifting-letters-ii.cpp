class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> line(s.length(),0);
        for(int i=0;i<shifts.size();i++){
            if(shifts[i][2]==0){
                line[shifts[i][0]]-=1;
                if(shifts[i][1]+1<line.size()){
                    line[shifts[i][1]+1]+=1;
                    
                }
            }
            else{
                line[shifts[i][0]]+=1;
                if(shifts[i][1]+1<line.size()){
                    line[shifts[i][1]+1]-=1;
                }
            }
        }
        for(int i=1;i<line.size();i++){
            line[i]=line[i-1]+line[i];
        }
        for(int i=0;i<s.length();i++){
			int increaseBy=(s[i]-'a'+line[i])%26;
			increaseBy=(increaseBy+26)%26;
			s[i]='a'+increaseBy;
        }
        
        return s;
    }
    
};