class Solution {
public:
    int numRabbits(vector<int>& answers) {
        //5 5 5 5 6 7 7 7 8 8 8 0 0 0  6+7+8+9+1
        unordered_map<int,int> m;
        for(int i=0;i<answers.size();i++){
            m[answers[i]]++;
        }
        int cnt=0;
        for(auto i:m){
            if(i.first!=0&&i.second%(i.first+1)==0){
                cnt+=((i.second)/(i.first+1))*(i.first+1);
            }
            else if(i.first!=0){
                cnt+=((i.second)/(i.first+1)+1)*(i.first+1);
            }
        }
        if(m.find(0)!=m.end()){
            return cnt+m[0];
        }
        return cnt;
    }
};