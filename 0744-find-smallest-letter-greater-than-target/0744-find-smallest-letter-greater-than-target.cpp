class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s=0;
        int e=letters.size()-1;
        int mid=(s+e)/2;
        if(letters[letters.size()-1]<=target){
            return letters[0];
        }
        int ans;
        while(s<=e){
            if(letters[mid]>target){
                e=mid-1;
                ans=mid;
            }
            else{
                s=mid+1;
                
            }
            mid=(s+e)/2;
        }
        return letters[ans];
    }
};