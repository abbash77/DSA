class Solution {
public:
    bool isVowel(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || 
                   x == 'o' || x == 'u')
        return true;
   return false;
}
    int maxVowels(string s, int k) {
        int vowelCnt=0;
        int maxi=INT_MIN;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                vowelCnt++;
            }
        }
        maxi=max(maxi,vowelCnt);
        int j=0;
        for(int i=k;i<s.length();i++){
            if(isVowel(s[i])){
                vowelCnt++;
            } 
            if(isVowel(s[j])){
                vowelCnt--;
            }
            j++;
            maxi=max(maxi,vowelCnt);
        }
        return maxi;
    }
};