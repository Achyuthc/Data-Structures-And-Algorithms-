/*You are given an integer array rolls of length n and an integer k. You roll a k sided dice numbered from 1 to k, n times, where the result of the ith roll is rolls[i].

Return the length of the shortest sequence of rolls that cannot be taken from rolls.

A sequence of rolls of length len is the result of rolling a k sided dice len times.

Note that the sequence taken does not have to be consecutive as long as it is in order.*/


observe that we can get length when we have number(all k should have frequency of atleast one then we can obtain presetn ans+1 length rolls sequence)
eg1) [1,1,2,3,4,4,3,2] k=4

[1,1,2,3,4] [4,3,2] can contribute for different part of length
we can obtain all possible rolls except roll [2,1] [3,1] [4,1] because we can choose 2,3,4 from 1st array but we cannot choose 1 from 2nd array .

eg2:
[1,2,3,3,3,3,4,1,2,4,3,1,2,3,4]
we can [1,2,3,3,3,4] [1,2,4,3] [1,2,3,4] 3 possible arrays and we can choose every element<=k from every array so we can obtain all possible rolls sequence <=3

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ans=0;
        int freq[k+1];
        memset(freq,0,sizeof(freq));
        int i=0;
        int cnt=0;
        while(i<rolls.size())
        {
            freq[rolls[i]]++;
            if(freq[rolls[i]]==1)
                cnt++;
            if(cnt==k)
            {
                cnt=0;
                ans++;
                memset(freq,0,sizeof(freq));
            }
              
            i++;
        }
        return ans+1;
    }
};
