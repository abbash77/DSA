enum Color {WHITE, GRAY, BLACK};

class Solution {
    vector<vector<int>> graph;
    vector<int> color;
public:
    bool dfs(int u){
        color[u]=GRAY;
        for(auto v:graph[u]){
            if(color[v]==WHITE && dfs(v)) 
                return true;
            else if(color[v]==GRAY)
                return true;
        }
        color[u]=BLACK;
        return false;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size(), j;
        graph.resize(n);
        color.resize(n, WHITE);

        for(int i=0; i<n; i++){
            int jump = abs(nums[i])%n;
            nums[i]>0 ? j=(i+jump)%n : j=(i-jump+n)%n;
            if(i==j || (nums[i]<0 && nums[j]>0) || (nums[i]>0 && nums[j]<0))
                continue;
            graph[i].push_back(j);
        }

        for(int i=0; i<n; i++){
            if(color[i]==WHITE && dfs(i))
                return true;
        }
        return false;
    }
};