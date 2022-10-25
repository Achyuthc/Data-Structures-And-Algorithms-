/*
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.
*/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        bool isSame=true;
        int i=0,j=0,index1=0,index2=0;
        while(i<word1.size()&&j<word2.size())
        {
            if(index1==word1[i].size())
            {
                i++;
                index1=0;
            }
            if(index2==word2[j].size())
            {
                j++;
                index2=0;
            }
            if(i<word1.size()&&j<word2.size()&&word1[i][index1]!=word2[j][index2])
                return false;
            index1++;
            index2++;
        }
        return i==word1.size()&&j==word2.size();
        
    }
};
