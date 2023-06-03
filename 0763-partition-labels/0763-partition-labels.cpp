class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i;
        }
        vector<int> ans;
        int i=0;
        while(i<s.length()){
            int end=m[s[i]];
            for(int j=i;j<=end;j++){
                int e=m[s[j]];
                if(e>end){
                    end=e;
                }
            }
            ans.push_back(end+1-i);
            i=end+1;
            
        }
        return ans;
    }
};