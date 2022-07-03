/*You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:

Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
Align the substitution table with the regular English alphabet.
Each letter in message is then substituted using the table.
Spaces ' ' are transformed to themselves.
For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
Return the decoded message.*/

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> mp;
        int a[26];
        memset(a,0,sizeof(a));
        char ch='a';
        for(char &c:key)
        {
            if(c==' ')
                continue;
            if(a[c-'a']==0)
            {
                mp[c]=ch;
                
                ch++;
            }
            a[c-'a']++;
            
        }
        
        for(int i=0;i<message.size();i++)
        {
            if(message[i]==' ')
                continue;
            message[i]=mp[message[i]];
        }
        
        return message;
    }
};
