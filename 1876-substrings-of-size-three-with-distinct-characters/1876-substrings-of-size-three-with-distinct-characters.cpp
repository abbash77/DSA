class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size(); 
        int k = 3; // Required window size 
        
        unordered_map<char,int> mp;
        int i=0,j=0; // i is starting index of window and j is ending index of window
        int count = 0; // Subarrays count
        
        while(j<n)
        {
            mp[s[j]]++; // Adding the frequency of jth character in map
            
            if(j-i+1<3) // If window size of 3 is not achieved
                j++;
            
            else if(j-i+1==3)  // If window size of 3 is achieved
            {
                if(mp.size()==(j-i+1)) // Checking if all the characters in window are unique
                {
                    count += 1;
                    
                    mp[s[i]]--; // Before sliding the window make sure to decrease the count of starting index character of window 
                    if(mp[s[i]]==0) 
                        mp.erase(s[i]);
                    
					// Sliding the window
                    i++; 
                    j++;
                    
                }
                
                else if(mp.size()<(j-i+1)) // // if all the characters in window are not unique
                {
                    while(mp.size()<(j-i+1) && i<=j) // Removing the ith character from window until we have removed all the duplicate characters
                    {
                        mp[s[i]]--;
                        if(mp[s[i]]==0)
                            mp.erase(s[i]);
                        i++;
                    }
                    j++;
                }                
            }
        }
        
        return count;
    }
};