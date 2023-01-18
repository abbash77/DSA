class trienode{
  public:
    char data;
    bool isTerminal;
    trienode* children[26];
    trienode(char ch){
        data =ch;
        isTerminal=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class WordDictionary {
public:
    trienode* root;
    WordDictionary() {
        root=new trienode('\0');
    }
    
    void addWord(string word) {
        add(root,word);
    }
    void add(trienode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new trienode(word[0]);
            root->children[index]=child;
        }
        add(child,word.substr(1));
    }
    
    bool search(string word) {
        return searching(root,word,0);
    }
    bool searching(trienode* node,string word,int pos){
        if(pos == word.size())
            return node->isTerminal;
       
	   // if there's no '.', we can just iterate in our linked list
        if (word[pos] != '.'){
            node = node->children[word[pos] - 'a'];
			// this 'node' before the search is to avoid unnecessary recursion calls (if node is null, the linked list was ended up)
			// we increment our 'pos' by 1, in order to search the next character, if it exists
            return node && searching(node, word, pos + 1);
        }
        
		// if there's a '.', we need to force iteration in all possible cases
        for (int i = 0; i < 26; i++)
			// 'node->children[i]' is here to avoid unnecessary recursion calls (if this node->children[i] is null, the linked list was ended up)
            if(node->children[i] && searching(node->children[i],word, pos + 1))
                return true;
        return false;     
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */