class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int c=0;
        int maxi=INT_MIN;
        int maxiIndex=0;
        for(int i=0;i<releaseTimes.size();i++){
            int a=releaseTimes[i]-c;
            if(a>maxi){
                maxi=a;
                maxiIndex=i;
            }
            else if(a==maxi){
                maxi=a;
                if(keysPressed[maxiIndex]<keysPressed[i]){
                    maxiIndex=i;
                }
            }
            c=releaseTimes[i];
        }
        return keysPressed[maxiIndex];
    }
};