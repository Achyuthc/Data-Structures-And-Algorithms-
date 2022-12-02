/*Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 */


https://leetcode.com/problems/determine-if-two-strings-are-close/solutions/2870592/c-solution-with-frequency/


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int a[26],b[26];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));

        if(word1.size()!=word2.size())
            return false;
        
        for(int i=0;i<word1.size();i++)
        {
            a[word1[i]-'a']++,b[word2[i]-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if(a[i]==0)
                continue;
            else
            if(a[i]==b[i])
            {
                a[i]=0,b[i]=0;
            }
            else
            {
                bool possible=false;
                for(int j=0;j<26;j++)
                {
                    if(a[i]==b[j]&&b[i]!=0&&a[j]!=0)
                    {
                        //cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<" "<<b[i]<<" "<<b[j]<<"\n";
                        b[j]=b[i];
                        a[i]=0,b[i]=0;
                        possible=true;
                        
                        break;

                    }
                }
                if(!possible)
                    return false;
            }
            
        }
        for(int i=0;i<26;i++)
        {
            if(a[i]!=0||b[i]!=0)
            return false;
        }
        return true;
    }
};
