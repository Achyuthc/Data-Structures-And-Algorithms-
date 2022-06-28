/*A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

 */

class Solution {
public:
    int minDeletions(string s) {
       int frequency[26];
        memset(frequency,0,sizeof(frequency));
        for(int i=0;i<s.size();i++)
        {
            frequency[s[i]-'a']++;
        }
        sort(frequency,frequency+26);
        int ans=0;
        for(int i=24;i>=0;i--)
        {
            if(frequency[i+1]==frequency[i]&&frequency[i]!=0)
            {
                frequency[i]--;
                ans++;
            }
            else if(frequency[i+1]<frequency[i])
            {
                if(frequency[i+1]==0)
                {
                    ans+=frequency[i];
                    frequency[i]=0;
                    
                }
                else
                {
                    ans+=frequency[i]-frequency[i+1]+1;
                    frequency[i]=frequency[i+1]-1;
                }
            }
        }
        return ans;
    
    }
};
