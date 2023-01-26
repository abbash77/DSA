class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0;
        double mini=INT_MAX;
        double maxi=INT_MIN;
        for(int i=0;i<salary.size();i++){
            // mini=min(salary[i],mini);
            if(salary[i]<mini){
                mini=salary[i];
            }
            if(salary[i]>maxi){
                maxi=salary[i];
            }
            
            sum+=salary[i];
        }
        return (sum-maxi-mini)/(salary.size()-2);
    }
};