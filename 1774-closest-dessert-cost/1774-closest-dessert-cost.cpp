class Solution {
public:
    void solve(int i,vector<int>& top,int t,int sf,int& ans,int& diff){
    // base case
    if(i == top.size()){
        
        if(abs(t-sf) < diff){    // if the diff of cost if less than prev found diff
            diff = abs(t-sf);          
            ans = sf;
        }
        else if(abs(t-sf) == diff)   // if diff is same but value of cost is smaller
            ans = min(ans,sf);
            
        return;
    }
    
    solve(i+1, top,t, sf, ans, diff);           // No topping[i]
    solve(i+1, top,t, sf+top[i], ans, diff);     // One topping[i]
    solve(i+1, top,t, sf+(2*top[i]), ans, diff);    // Both topping[i]
}

int closestCost(vector<int>& b, vector<int>& t, int tar) {
    
    int ans = INT_MAX;
    int diff = INT_MAX;
    
    for(auto& x: b){     // Taking each base as a start cost
        solve(0,t,tar,x,ans,diff);
    }
    
    return ans;
}
};