
/*You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).*/

class Solution {
public:
    int maximum69Number (int num) {
        int rev=0;
        while(num>0)
        {
            rev=rev*10+num%10;
            num/=10;
        }
        int ans=0,cnt=1;
        while(rev>0)
        {
            if(rev%10==6&&cnt>0)
            {
                cnt--;
                ans=ans*10+9;
            }
            else
            {
                ans=ans*10+rev%10;
            }
            rev/=10;
        }
        return ans;
    }
};
