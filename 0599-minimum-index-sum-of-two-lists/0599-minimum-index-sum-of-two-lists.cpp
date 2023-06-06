class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> m;
        map<int,vector<string> > m2;
        for(int i=0;i<list2.size();i++){
            m[list2[i]]=i;
        }
        for(int i=0;i<list1.size();i++){
            if(m.find(list1[i])!=m.end()){
                m2[i+m[list1[i]]].push_back(list1[i]);
            }
        }
        int a;
        for(auto i:m2){
            a=i.first;
            break;
        }
        vector<string> v;
        for(auto i:m2){
            for(auto j:i.second){
                v.push_back(j);
            }
            break;
        }
        return v;
    }
};