/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int ans=0;
    void dfs(int node,unordered_map<int,pair<int,vector<int>>> m,unordered_map<int,bool> &visited){
        ans+=m[node].first;
        visited[node]=true;
        for(auto neigh:m[node].second){
            if(visited.find(neigh)==visited.end()){
                dfs(neigh,m,visited);
            }
            
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,pair<int,vector<int>>> m;
        unordered_map<int,bool> visited;
        for(int i=0;i<employees.size();i++){
            int id=employees[i]->id;
            int imp=employees[i]->importance;
            m[id].first=imp;
            for(int j=0;j<employees[i]->subordinates.size();j++){
                m[id].second.push_back(employees[i]->subordinates[j]);
            }
        }
        dfs(id,m,visited);
        return ans;
    }
};