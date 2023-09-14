class Solution {
public:
    vector<string> ans;
    void solve(string curNode, unordered_map<string, priority_queue<string,vector<string>,greater<string>>> &graph){
    priority_queue<string,vector<string>,greater<string>> &pq = graph[curNode];
    while(!pq.empty()){
        string childNode = pq.top();
        pq.pop();
        solve(childNode, graph);
    }
    ans.push_back(curNode);
    return;
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string,vector<string>,greater<string>>> graph;
        for(auto &t : tickets){
            graph[t[0]].push(t[1]);
        }
        solve("JFK",graph);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};