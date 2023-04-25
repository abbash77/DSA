class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int gs) {
        int n = hand.size();
        if(n % gs != 0)
            return false;

        map<int,int> mp;
        for(auto h : hand)
            mp[h]++;
        
        int prev;
        while(!mp.empty())
        {
            int startVal = mp.begin()->first;
            for(int i = 0; i < gs; i++)
            {
                if(mp.find(startVal+i) == mp.end())
                    return false;
                mp[startVal+i]--;
                if(mp[startVal+i] == 0)
                    mp.erase(startVal+i);
            }
        }
        return true;
    }
};