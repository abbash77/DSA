class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        int ans=0;
        for(auto i:m){
            if(i.second==2||i.second==3){
                ans++;
                i.second=0;
            }
            else if(i.second==1){
                return -1;
            }
            else if(i.second>3){
                while(i.second!=0){
                    if(i.second%3==0){
                        i.second=i.second-3;
                        ans++;
                    }
                    else{
                        i.second=i.second-2;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};