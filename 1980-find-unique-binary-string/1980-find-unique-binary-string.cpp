class Solution {
public:
    string ans="";
    void recur(string str,int n,set<string> s){
        if(n==0){
            if(s.find(str)==s.end()){
                ans=str;
            }
            return;
        }
        if(ans.length()==0){
            recur(str+'0',n-1,s);
        }
        if(ans.length()==0){
            recur(str+'1',n-1,s);
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        string str="";
        set<string> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        recur(str,n,s);
        return ans;
    }
};