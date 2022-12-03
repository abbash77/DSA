class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        string st="";
        while(!pq.empty()){
            auto i=pq.top();
            pq.pop();
            int n=i.first;
            char a=i.second;
            for(int j=0;j<n;j++){
                st+=a;
            }
        }
        return st;
    }
};