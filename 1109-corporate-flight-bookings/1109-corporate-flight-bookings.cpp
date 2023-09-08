class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
         vector<int> v(n+1,0);
       
        for(int i=0;i<bookings.size();i++){
            v[bookings[i][0]-1]+=bookings[i][2];
            v[bookings[i][1]]+=(-bookings[i][2]);
        }
        v.pop_back();
        for(int i=1;i<v.size();i++){
            v[i]=v[i]+v[i-1];
        }
        return v;
    }
};