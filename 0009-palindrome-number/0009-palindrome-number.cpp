class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> v;
        if(x<0){
            return false;
        }
        while(x>=10){
            v.push_back(x%10);
            x=x/10;
        }
        v.push_back(x);
        int s=0;
        int e=v.size()-1;
        while(s<e){
            if(v[s]!=v[e]){
                return false;
            }
            else{
                s++;
                e--;
            }
        }
        return true;
    }
};