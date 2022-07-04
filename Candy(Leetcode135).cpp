/*There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 */

class Solution {
public:
    int candy(vector<int>& ratings) {
       int n=ratings.size();
       vector<int> candies(n);
       for(int i=0;i<n;i++)
           candies.push_back(1);
       for(int i=0;i<n;i++)
       {
           if(i-1>=0&&ratings[i]>ratings[i-1])
                candies[i]=candies[i-1]+1;
       }
       for(int i=n-1;i>=0;i--)
       {
           if(i+1<n&&ratings[i]>ratings[i+1])
               candies[i]=max(candies[i],candies[i+1]+1);
       }
       int ans=0;
       for(int c:candies)
           ans+=c;
        return ans;
    }
};
