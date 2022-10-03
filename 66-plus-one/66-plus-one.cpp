class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
         reverse(digits.begin(),digits.end());
        int nums;
        int carry;
        for(int i=0;i<digits.size();i++){
            if(i==0){
                nums=digits[i]+1;
            }
            else{
                nums=digits[i]+carry;
            }
            carry=nums/10;
            int x=nums%10;
            digits[i]=x;
            
        }
        if(carry!=0){
            digits.push_back(carry);
        }
         reverse(digits.begin(),digits.end());
        return digits;
    }
};