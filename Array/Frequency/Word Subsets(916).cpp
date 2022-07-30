/*You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.*/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        int a[26];
        memset(a,0,sizeof(a));
        int b[26];
        memset(b,0,sizeof(b));
        for(auto w2:words2){
            for(char c:w2)
            {
                b[c-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                a[i]=max(a[i],b[i]);
                b[i]=0;
            }
        }
        vector<string> ans;
        for(auto w1:words1){
            bool flag=true;
            for(char c:w1){
                b[c-'a']++;
                
            }
            for(int i=0;i<26;i++){
                if(b[i]<a[i])
                {
                    flag=false;
                    break;
                }
                
            }
            memset(b,0,sizeof(b));
            if(flag)
                ans.push_back(w1);
        }
        return ans;
        
    }
};
