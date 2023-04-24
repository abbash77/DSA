class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),cmp);
        map<int,int> m;
        // for(int i=0;i<trips.size();i++){
        //     m[trips[i][2]]+=trips[i][0];
        // }
        int cap=capacity;
        cap-=trips[0][0];
        if(cap<0){
            return false;
        }
        int start=trips[0][1];
        int end=trips[0][2];
        m[trips[0][2]]=trips[0][0];
        for(int i=1;i<trips.size();i++){
            for(auto k:m){
                if(k.first<=trips[i][1]){
                    cap+=k.second;
                    m.erase(k.first);
                }
                else{
                    break;
                }
            }
            if(start<trips[i][1]<end){
                cap-=trips[i][0];
                if(cap<0){
                    return false;
                }
                end=trips[i][2];
                m[trips[i][2]]+=trips[i][0];
            }else{
                cap=capacity;
                start=trips[i][1];
                end=trips[i][2];
                m.clear();
            }
        }
        return true;
    }
};