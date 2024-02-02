class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
          string s="123456789";
        vector<int> v;
        int lowLen=to_string(low).length();
        int highLen=to_string(high).length();
       
        for(int i=lowLen;i<=highLen;i++){
            for(int j=0;i!=10&&j<=s.length()-i;j++){
                int a=stoi(s.substr(j,i));
                if(a>=low && a<=high){
                    v.push_back(a);
                }
            }
        }
        return v;
    }
};