


/*Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.*/


solution:https://leetcode.com/problems/reverse-vowels-of-a-string/solutions/2778695/c-with-2-pointers/

class Solution {
public:
    string reverseVowels(string s) {
        int low=0,high=s.size()-1;
        unordered_map<char,int> vowel;
        vowel['a']=1,vowel['A']=1;
        vowel['e']=1,vowel['E']=1;
        vowel['i']=1,vowel['I']=1;
        vowel['o']=1,vowel['O']=1;
        vowel['u']=1,vowel['U']=1;
        char temp;
        while(low<high)
        {
            if(vowel[s[low]]==0)
            {
                low++;
            }
            else if(vowel[s[high]]==0)
            {
                high--;
            }
            else
            {
                temp=s[low];
                s[low]=s[high];
                s[high]=temp;
                low++;
                high--;
            }
        }
        return s;
    }
};
