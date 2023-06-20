class Solution {
public:
    static bool cmp(pair<int,pair<int,int>> a ,pair<int,pair<int,int>> b){
        if(a.first==b.first){
            return a.second.first<b.second.first;
        }
        return a.first<b.first;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            string t="";
            while(temp>0){
                int a=temp%10;
                int b=mapping[a];
                t+=(b+'0');
                temp=temp/10;
            }
            reverse(t.begin(),t.end());
            
            int b;
            if(t==""){
                b=mapping[0];
            }
            else{
                b=stoi(t);
            }
            v.push_back({b,{i,nums[i]}});
            
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        for(auto i:v){
            ans.push_back(i.second.second);
        }
        return ans;
    }
};