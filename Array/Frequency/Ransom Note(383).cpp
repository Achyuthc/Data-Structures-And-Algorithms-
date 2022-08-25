/*Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int frequency[26];
        memset(frequency,0,sizeof(frequency));
        for(char &c:magazine)
            frequency[c-'a']++;
        
        for(char &c:ransomNote)
            frequency[c-'a']--;
        
        for(int i=0;i<26;i++)
            if(frequency[i]<0)
                return false;
        return true;
    }
};
