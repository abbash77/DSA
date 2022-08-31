class Solution {
public:
    int romanToInt(string s) {
        int count =0;
        map<char,int> m;
        m['I']=1;
         m['V']=5;
        m['X']=10;
         m['L']=50;
        m['C']=100;
         m['D']=500;
        m['M']=1000;
        for(int i=0;i<s.length();i++){
            if(i==0){
                count+=m[s[i]];
            }
            else{
                if(m[s[i-1]]<m[s[i]]){
                    count=count-2*m[s[i-1]];
                    
                }
                count+=m[s[i]];
            }
        }   
        
        return count;
    }
};