/*Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.*/

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(char c:s)
        {
            mp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        int i=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            while(it.first!=0)
            {
                s[i++]=it.second;
                it.first--;
            }
        }
        return s;
    }
};
