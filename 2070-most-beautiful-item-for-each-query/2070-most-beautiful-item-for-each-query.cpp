class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int> m;
        vector<int> khu;
        vector<vector<int>> ans;
        sort(items.begin(),items.end());
        for(int i=0;i<items.size();i++){
            m[items[i][0]]=items[i][1];
        }
   
        for(auto i:m){
            vector<int> v;
            v.push_back(i.first);
            v.push_back(i.second);
            ans.push_back(v);

        }
     
        int maxi=INT_MIN;
        vector<vector<int>> finale;
        for(int i=0;i<ans.size();i++){
               vector<int> v;
            if(ans[i][1]>maxi){
                maxi=ans[i][1];
            }
            v.push_back(ans[i][0]);
            v.push_back(maxi);
            finale.push_back(v);
        }       
        for(int i=0;i<queries.size();i++){
             int answ=0;
            int a=queries[i];
            int start=0;
            int end=finale.size()-1;
           
            while(start<=end){
                 int mid=start+(end-start)/2;
                if(finale[mid][0]==a){
                    answ=finale[mid][1];
                    break;
                }
                else if(finale[mid][0]<a){
                    answ=finale[mid][1];
                   start=mid+1;
                   
                   
                }
                else{
                    end=mid-1;
                   
                }
            }
            khu.push_back(answ);
        }
        return khu;
    }
};