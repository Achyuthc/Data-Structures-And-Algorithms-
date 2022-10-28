/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<pair<string,int>> duplicate;

        for(int i=0;i<strs.size();i++)
        {
            duplicate.push_back({strs[i],i});
            sort(duplicate[i].first.begin(),duplicate[i].first.end());
        }
        sort(duplicate.begin(),duplicate.end());

        for(int i=0;i<strs.size();i++)
        {
            if(i==0||duplicate[i].first!=duplicate[i-1].first)
            {
                ans.push_back({strs[duplicate[i].second]});
            }
            else
            {
                ans.back().push_back(strs[duplicate[i].second]);
            }
        }
        return ans;
    }
};
