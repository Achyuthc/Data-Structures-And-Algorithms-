/*You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. 
Since the answer can be a large number, return this modulo 109 + 7.*/


class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long length=0,height=0,modulo=1e9+7;
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        for(int i=1;i<horizontalCuts.size();i++)
        {
            if(horizontalCuts[i]-horizontalCuts[i-1]>height)
                height=horizontalCuts[i]-horizontalCuts[i-1];
            
        }
        
        for(int i=1;i<verticalCuts.size();i++)
        {
            if(verticalCuts[i]-verticalCuts[i-1]>length)
                length=verticalCuts[i]-verticalCuts[i-1];
        }
        
        return (length*height)%modulo;
    }
};
