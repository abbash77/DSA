class Solution {
public:
    bool isSubsequence(string &s1, string &s2){
        int m=s1.length();
        int n=s2.length();
        int j = 0;
        for(int i = 0; i < m && j < n; i++){
            if(s1[i] == s2[j]) j++;
        }
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt=0;
        unordered_map<string,bool> m;
        for(int i=0;i<words.size();i++){
            if(m.find(words[i])!=m.end()){
                cnt++;
            }
            else if(isSubsequence(s,words[i])){
                m[words[i]]=true;
                cnt++;
            }
        }
        return cnt;
    }
};