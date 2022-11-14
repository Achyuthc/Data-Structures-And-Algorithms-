/*On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 */


class Solution {
public:
    int islands=0;
    map<int,int> findMap;
    int find(int x)
    {
        if(findMap.find(x)==findMap.end())
            findMap[x]=x,islands++;
        else if(x!=findMap[x])
            findMap[x]=find(findMap[x]);

        return findMap[x];
    }
    void uni(int x,int y)
    {
        int fx=find(x),fy=find(y);
        if(fx!=fy)
        {
            findMap[fx]=fy;
            islands--;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        

        for(auto &s:stones)
            uni(s[0],10001+s[1]);
        return stones.size()-islands;
    }
};
