/*A frog starts at the point 0. In his first turn, he can make a jump of 1 unit. Now for all consequent turns, if the frog is currently at a distance x (from the start), his jump will take him x units forward. 
Given a leaf at a distance N, you have to find if the frog can reach that leaf or not.*/

class Solution {
  public:
  
    string canJump(long long N) {
        // code here
        //cout<<((N-1)&N)<<" ";
        if(N==0)
            return "False";
        if(((N-1)&N)==0)
            return "True";
        return "False";
    }
};
