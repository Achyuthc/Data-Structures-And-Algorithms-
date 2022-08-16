/*Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 */

class Solution {
public:
    int firstUniqChar(string s) {
        int frequency[26];
        memset(frequency,0,sizeof(frequency));
        int i=0;
        for(char &c:s)
        {
            frequency[c-'a']++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(frequency[s[i]-'a']==1)
                return i;
        }
    
        return -1;
        
    }
};
