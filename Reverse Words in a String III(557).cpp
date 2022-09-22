
/*Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.*/

class Solution {
public:
    string reverseWords(string s) {
        
        
        int i=0;
        string ans="";
        while(i<s.size())
        {
            string str="";
            while(i<s.size()&&s[i]!=' ')
            {
                str.push_back(s[i++]);
            }
            reverse(str.begin(),str.end());
            ans+=str+" ";
            i++;
        }
        ans.pop_back();
        return ans;
        
    }
};
