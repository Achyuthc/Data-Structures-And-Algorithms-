/*Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.
*/

Question: https://leetcode.com/problems/make-the-string-great/description/
Solution :https://leetcode.com/problems/make-the-string-great/solutions/2793708/c-solution/


class Solution {
public:
    string makeGood(string s) {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(i==0)
            {
                ans.push_back(s[i]);
            }
            else if((ans.back()-'a'==s[i]-'A')||(ans.back()-'A')==s[i]-'a')
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
