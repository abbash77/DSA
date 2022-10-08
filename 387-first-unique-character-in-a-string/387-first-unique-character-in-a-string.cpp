class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        queue<char> q;
        for(int i=0;i<s.length();i++){
            q.push(s[i]);
        }
        while(!q.empty()){
            char z=q.front();
            q.pop();
            if(m[z]==1){
                return s.find(z);
            }
        }
        return -1;
    }
};