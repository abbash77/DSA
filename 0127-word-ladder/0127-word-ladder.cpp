class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string>s ;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }
        s.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int val=q.front().second;
            if(word==endWord){
                return val;
            }
            q.pop();
            for(int i=0;i<word.size();i++)
            {
                for(char j='a';j<='z';j++){
                    // if(word[i]!=j){
                        string dummy=word;
                        dummy[i]=j;
                        if(s.find(dummy)!=s.end()){
                            q.push({dummy,val+1});
                            s.erase(dummy);
                        }
                    // }
                    
                }
            }        
        }
        return 0;
        
    }
};