class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
      for(string s:words)
      {
          map<char,char> mp;
          set<char> st;
          map<char,char> mp1;
          set<char> st1;
          bool flag=false;
          if(s.size()!=pattern.size())
              continue;
          for(int i=0;i<s.size();i++)
          {
              if(st.find(pattern[i])!=st.end())
              {
                  if(mp[pattern[i]]!=s[i])
                  {
                       flag=true;
                      break;
                  }
              }
              mp[pattern[i]]=s[i];
              st.insert(pattern[i]);
          }
           for(int i=0;i<s.size();i++)
          {
              if(st1.find(s[i])!=st1.end())
              {
                  if(mp1[s[i]]!=pattern[i])
                  {
                       flag=true;
                      break;
                  }
              }
              mp1[s[i]]=pattern[i];
              st1.insert(s[i]);
          }
          if(!flag)
          ans.push_back(s);
      }
        return ans;
    }
};