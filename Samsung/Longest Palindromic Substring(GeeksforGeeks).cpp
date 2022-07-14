/*Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs
first ( with the least starting index ).*/

https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1/?page=1&status[]=solved&company[]=Samsung&sortBy=submissions


class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
          // code here
        int len=1;
        int indx=0;
        for(int mid=1;mid<s.size();mid++)
        {
            int i=mid-1,j=mid+1;
            int t=1;
            while(i>=0&&j<s.size()&&s[i]==s[j])
            {
                i--;
                j++;
                t+=2;
            }
            if(len<t)
            {
                len=t;
                indx=i+1;
            }
            i=mid-1,j=mid;
            t=0;
            while(i>=0&&j<s.size()&&s[i]==s[j])
            {
                i--;
                j++;
                t+=2;
            }
            if(len<t)
            {
                len=t;
                indx=i+1;
            }
        }
        return s.substr(indx,len);
    }
};
