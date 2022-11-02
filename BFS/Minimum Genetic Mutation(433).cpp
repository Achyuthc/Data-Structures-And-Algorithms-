/*A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,bool> outBank;
        queue<string> q;
        int ans=0;
        if(start.compare(end)==0)
            return 0;
        q.push(start);
        outBank[start]=true;

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                string s=q.front();
                q.pop();
                if(s.compare(end)==0)
                    return ans;
                for(auto b:bank)
                {
                    if(outBank[b]==true)
                        continue;
                    int cnt=0;
                    for(int k=0;k<start.size();k++)
                    {
                        if(s[k]!=b[k])
                            cnt++;
                    }
                    if(cnt==1)
                    {
                        outBank[b]=true;
                        q.push(b);
                    }
                }
            }
            ans++;
           
        }
         return -1;
    }
};
