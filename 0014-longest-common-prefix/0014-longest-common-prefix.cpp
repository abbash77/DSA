class trieNode{
    public:
    char data;
    trieNode* children[26];
    bool isTerminal;
    int no_of_child;
    trieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
        no_of_child=0;
    }
};
class trie{
    public:
    trieNode* root;
    trie(char ch){
        root=new trieNode(ch);
    }
    void insert(trieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        trieNode* child;
        if(root->children[index]){
            child=root->children[index];
        }
        else{
            child=new trieNode(word[0]);
            root->children[index]=child;
            root->no_of_child++;
        }
        insert(child,word.substr(1));
    }
    void insertWord(string word){
        insert(root,word);
    }
    void common(string s,string &ans){
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(root->isTerminal){
                break;
            }
            if(root->no_of_child==1){
                ans+=ch;
                int index=ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            
        }
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        trie* t=new trie('\0');
        for(int i=0;i<strs.size();i++){
            t->insertWord(strs[i]);
        }
        string ans="";
        string first=strs[0];
        t->common(first,ans);
        return ans;
    }
};