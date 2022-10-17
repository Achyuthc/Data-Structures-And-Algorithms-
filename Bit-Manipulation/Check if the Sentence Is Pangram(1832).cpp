/*A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

 */
https://leetcode.com/problems/check-if-the-sentence-is-pangram/solutions/2715140/c-solution-with-bits-in-int/
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int bits=0;

        for(auto &c:sentence)
        {
            bits=bits|(1<<(c-'a'));
        }

        for(int i=0;i<26;i++)
        {
            if(!(bits&(1<<i)))
                return false;

        }
        return true;
    }
};
