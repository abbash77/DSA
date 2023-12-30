class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> v;
        vector<int> ans;
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                v.push_back(i);
            }
        }
        if(v.size()==0){
            for(int i=0;i<boxes.size();i++){
                ans.push_back(0);
            }
            return ans;
        }
        vector<int> prefix(v.size(),0);
        prefix[0]=v[0];
        for(int i=1;i<v.size();i++){
            prefix[i]=prefix[i-1]+v[i];
        }
        vector<int> suffix(v.size(),0);
        
        suffix[v.size()-1]=v[v.size()-1];
        for(int i=v.size()-2;i>=0;i--){
            suffix[i]=suffix[i+1]+v[i];
        }
        
        for(int i=0;i<boxes.size();i++){
            int idx=lower_bound(v.begin(),v.end(),i)-v.begin();
    
            int aagelog=v.size()-idx;
            int a=0;
            if(idx<suffix.size()){
                a=suffix[idx]-aagelog*i;
            }
            
            int pichelog=idx;
            int b=0;
            if(pichelog>0){
                b=pichelog*i-prefix[idx-1];
            }
            ans.push_back(a+b);
        }
        return ans;
    }
};