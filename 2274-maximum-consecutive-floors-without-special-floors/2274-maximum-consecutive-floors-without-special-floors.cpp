class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int maxi=INT_MIN;
        maxi=max(maxi,special[0]-bottom);
        maxi=max(maxi,top-special[special.size()-1]);
        for(int i=0;i<special.size()-1;i++){
            maxi=max(maxi,special[i+1]-special[i]-1);
        }
        return maxi;
    }
};