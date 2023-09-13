class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0;
        int cap=capacity;
        for(int i=0;i<plants.size();i++){
            if(cap<plants[i]){
                ans+=2*(i);   
                ans++;
                cap=capacity;
                cap-=plants[i];
            }
            else{
                cap-=plants[i];
                ans++;
            }
        }
        return ans;
    }
};