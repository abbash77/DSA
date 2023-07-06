class Solution {
public:
    int minTimeToType(string word) {
        int cnt=0;
        if(word[0]=='a'){
            cnt++;
        }
        else{
            cnt+=min(word[0]-'a',26-abs(word[0]-'a'))+1;
        }
        for(int i=1;i<word.length();i++){
            cnt+=min(abs(word[i]-word[i-1]),26-abs(word[i]-word[i-1]))+1;
        }
        return cnt;
    }
};