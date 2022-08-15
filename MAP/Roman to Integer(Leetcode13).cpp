/**/

class Solution {
public:
    unordered_map<char,int> mp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}} ;
  
    int romanToInt(string s)
    {
        int ans=0,l=0;
        while(l<s.size())
        {
            if(l+1<s.size())
            {
                if(mp[s[l]]<mp[s[l+1]])
                    ans-=mp[s[l]];
                else
                    ans+=mp[s[l]];
            }
            else
            {
                ans+=mp[s[l]];
            }
          l++;
        }
     return ans;   
    }
};
