/*Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 */



class Solution {
public:
    int reverseNumber(int number)
    {
        int num=0;
        while(number>0)
        {
            num++;
            number/=10;
        }
        return num;
    }
    int compress(vector<char>& chars) {
        char prev,curr;
        int cnt=0,left=1,right,length=0;
        prev=chars[0];
        for(auto &curr:chars)
        {
            if(prev!=curr)
            {
                if(cnt!=1)
                {
                    length=reverseNumber(cnt);
                    right=length+left-1;
                    while(right>=left)
                    {
                        chars[right--]='0'+cnt%10;
                        cnt=cnt/10;
                    }
                    left+=length;
                    
                }
                chars[left++]=curr;
                prev=curr;
                cnt=1;
            }
            else
            {
                cnt++;
            }
        }
        if(cnt!=1)
        {
            length=reverseNumber(cnt);
            right=length+left-1;
            while(right>=left)
            {
                chars[right--]='0'+cnt%10;
                cnt=cnt/10;
            }
            left+=length;

        }
        return left;
    }
};
