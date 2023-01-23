class Solution {
public:
    string digitSum(string s, int k) {
        string h="";
        int sum=0;
        int m=0;
        while(s.length()>k){
            h="";
            for(int i=0;i<s.length();i++){
                if(m==k){
                    h+=to_string(sum);
                    m=0;
                    sum=0;
                }
                sum+=s[i]-48;
                m++;
            }
            if(m==k){
                    h+=to_string(sum);
                    m=0;
                    sum=0;
            }
            else if(m!=0){
                h+=to_string(sum);
                m=0;
                sum=0;
            }
            s=h;
        }
        return s;
    }
};