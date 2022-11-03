/*You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.*/
question:https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/
solution:https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/solutions/2774437/c-solution-with-frequencymap

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       unordered_map<string,int> frequencyOfWord;

       for(auto w:words)
       {
           frequencyOfWord[w]++;
       }
        int ans=0;
        int same=0,rem=0;
       for(auto w:words)
       {
           string rev=string(w.rbegin(),w.rend());
           if(w.compare(rev)==0&&frequencyOfWord[w]!=0)
           {
               same+=(frequencyOfWord[w]/2)*4;

               if(frequencyOfWord[w]%2==1)
                  rem=2;
               frequencyOfWord[w]=0;
           }
           else if(frequencyOfWord[w]!=0&&frequencyOfWord[rev]!=0)
           {
               ans+=4;
               frequencyOfWord[w]--;
               frequencyOfWord[rev]--;
           }
       }
       return ans+same+rem;
    }
};
