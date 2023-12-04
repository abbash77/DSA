class Solution {
public:
    string largestGoodInteger(string num) {
        int i=0;
        int j=1;
        string fans="";
        int ans1=-1;
        while(j<num.size()){
            if(num[i]==num[j]){
                j++;
                if(j-i==3){
                    string val=num.substr(i,3);
                    int ans=stoi(val);
                    if(ans>ans1){
                        ans1=ans;
                        fans=val;
                    }
                    i=j;
                    j++;
                }
            }
            else{
                i=j;
                j++;
            }
        }
        return fans;
    }
};