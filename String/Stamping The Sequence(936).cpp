/*You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.

In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.

For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
place stamp at index 0 of s to obtain "abc??",
place stamp at index 1 of s to obtain "?abc?", or
place stamp at index 2 of s to obtain "??abc".
Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
We want to convert s to target using at most 10 * target.length turns.

Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 * target.length turns, return an empty array.

 */

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        if(stamp==target)
            return {0};
        bool canStamp=true,stamped;
        vector<int> ans;
        int targetLength=target.size()-stamp.size()+1,i,j;
        while(canStamp)
        {
            canStamp=false;
            for(i=0;i<targetLength;i++)
            {
                for(j=0,stamped=false;j<stamp.size();j++)
                {
                    if(target[i+j]=='*')
                        continue;
                    else if(target[i+j]!=stamp[j])
                        break;
                    else
                        stamped=true;
                }

                if(stamped&&j==stamp.size())
                {
                    for(j=i;j<stamp.size()+i;j++)
						   target[j]='*';
					canStamp=true;
                    ans.push_back(i);
                }
           }
        }
            
        for(i=0;i<target.size();i++)
            if(target[i]!='*')
                return {};

        reverse(ans.begin(),ans.end());
        return ans;
    
    }
      
    
};
