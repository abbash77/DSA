class compare{
  public:
        bool operator()(int a, int b){
            // 30 34
            string s1 = to_string(a), s2=to_string(b);
            return s1+s2 > s2+s1;
            //3034>3430 false if false to swap
            
            //normal sort
            // 5 7 true to no swap
            //a<b
        }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(begin(nums),end(nums), compare());
        string s="";
        for(auto &n : nums) s+=to_string(n);
        if(nums[0]==0) return "0";
        return s;
    }
};