class Solution {
public:
    int titleToNumber(string columnTitle) {
        map<char,int> m;
        for(int i=1;i<=26;i++){
            m['A'+i-1]=i;
        }
        int cnt=0;
        int j=0;
        for(int i=columnTitle.length()-1;i>=0;i--){
            cnt+=pow(26,j)*m[columnTitle[i]];
            j++;
        }
        return cnt;
    }
    
};