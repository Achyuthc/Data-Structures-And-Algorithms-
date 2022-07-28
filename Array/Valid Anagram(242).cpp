/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 */

class Solution {
public:
    bool isAnagram(string s, string t) {
            map<char,int> m1;
            map<char,int> m2;
            int i,n1=s.size(),n2=t.size();
            if(n1!=n2)
                    return false;
            for(i=0;i<n1;i++)
            {
                    m1[s[i]]++;
                    m2[t[i]]++;
            }
             char c='a';
             for(c='a';c<='z';c++)
             {
                      if(m1[c]!=m2[c])
                              return false;
             }
            return true;
            
        
    }
};
