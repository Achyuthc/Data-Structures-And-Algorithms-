/*We call a positive integer special if all of its digits are distinct.

Given a positive integer n, return the number of special integers that belong to the interval [1, n].

 */

class Solution {
public:
    int countSpecialNumbers(int n) {
        vector<int> number;
        int num=n+1,ans=0;
        while(num>0)
        {
            number.push_back(num%10);
            num=num/10;
        }
        reverse(number.begin(),number.end());
        
    
        for(int i=1;i<number.size();i++)
        {
            ans+=9*A(9,i-1);
        }
        unordered_set<int> seen;
        for(int i=0;i<number.size();i++)
        {
            for(int j=i>0? 0:1;j<number[i];j++)
            {
                if(!seen.count(j))
                {
                    ans+=A(9-i,number.size()-i-1);
                }
            }
            
            if(seen.count(number[i]))
                break;
            seen.insert(number[i]);
            
        }
        
        return ans;
    }
        
        
        int A(int m,int n)
        {
            if(n==0)
                return 1;
            else
                return A(m,n-1)*(m-n+1);
        }
        
    
};
