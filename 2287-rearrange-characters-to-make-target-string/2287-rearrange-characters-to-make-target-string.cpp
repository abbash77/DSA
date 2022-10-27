class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        int c=0;
        while(true){
            int a=0;
            for(int i=0;i<target.length();i++){
                if(m[target[i]]>0){
                    m[target[i]]--;
                }
                else{
                    a=1;
                    break;
                }
            }
            if(a==0){
                c++;
            }
            if(a==1){
                break;
            }
        }
        return c;
    }
};