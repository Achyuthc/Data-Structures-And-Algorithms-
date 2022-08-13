/*You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
       
        int n=words[0].size(),m=words.size();
        unordered_map<string,int> exist;
        for(auto &word:words)
        {
            exist[word]++;
        }
        string str="";
        for(int i=0;i<words[0].size();i++)
        {
            int j=i;
            int cnt=0;
            int prev=i;
        
            while(j+words[0].size()<=s.size())
            {
                str=s.substr(j,words[0].size());
                if(exist[str]>=1){
                    exist[str]-=1;
                    j+=words[0].size();
                    cnt++;
                }
                else if(exist.find(str)==exist.end())
                {
                    while(prev!=j)
                    {
                        exist[s.substr(prev,words[0].size())]+=1;
                        prev+=words[0].size();
                    }
                    j+=words[0].size();
                    prev=j;
                    cnt=0;
                }
                else
                {
                    
                    while(exist[str]==0)
                    {
                        cnt--;
                        exist[s.substr(prev,words[0].size())]+=1;
                        prev+=words[0].size();
                    }
                    if(exist[str]==1)
                    {
                        cnt++;
                        exist[str]-=1;
                        j+=n;
                    }
                }
                 
                
                if(cnt==words.size())
                {
                      ans.push_back(prev); 
                }
               
                if(j-prev==n*m)
                {
                       
                    exist[s.substr(prev,words[0].size())]+=1;
                    prev=prev+words[0].size();
                    cnt--;
                }
                
            }
            while(prev<j)
            {
                exist[s.substr(prev,words[0].size())]+=1;
                prev+=words[0].size();
            }
        }
        
        return ans;
        
        
    }
};
