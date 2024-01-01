class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> population(101,0);
        for(int i=0;i<logs.size();i++){
            population[logs[i][0]-1950]++;
            population[logs[i][1]-1950]--;
        }
        int sum=0;
        int maxi=INT_MIN;
        int ans=0;
        for(int i=0;i<population.size();i++){
            sum+=population[i];
            if(maxi<sum){
                maxi=sum;
                ans=i+1950;
            }
        }
        return ans;
    }
};