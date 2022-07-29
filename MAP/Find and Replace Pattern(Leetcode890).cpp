/*Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.*/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto word:words)
        {
            unordered_map<char,char>mp1,mp2;
            bool flag=true;
            for(int i=0;i<pattern.size();i++)
            {
                if(mp1.find(word[i])==mp1.end())
                {
                    if(mp2.find(pattern[i])==mp2.end())
                    {
                        mp1[word[i]]=pattern[i];
                        mp2[pattern[i]]=word[i];
                    }
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                else if(pattern[i]!=mp1[word[i]]||word[i]!=mp2[pattern[i]])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(word);
        }
        return ans;
        
    }
};
