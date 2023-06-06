class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        //s1>s2
        bool a=false;
        for(int i=0;i<s1.length();i++){
            if(s1[i]>=s2[i]){
                
            }
            else{
                a=true;
                break;
            }
        }
        bool b=false;
        for(int i=0;i<s1.length();i++){
            if(s1[i]<=s2[i]){
                
            }
            else{
                b=true;
            }
        }
        if(a&&b){
            return false;
        }
        return true;
    }
};