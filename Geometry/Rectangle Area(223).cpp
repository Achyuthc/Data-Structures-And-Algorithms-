/*Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).

The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

 */
Question: https://leetcode.com/problems/rectangle-area/
Solution: https://leetcode.com/problems/rectangle-area/solutions/2823812/c-solution-area-of-union-aub-area-of-a-area-of-b-area-of-a-b/
Area of Union(AUB)=Area of (A)+Area of (B)- Area of(A∩B)


class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
      int startXmax=max(ax1,bx1),startYmax=max(ay1,by1),endXmin=min(ax2,bx2),endYmin=min(ay2,by2);
      return (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1)-max(endXmin-startXmax,0)*max(endYmin-startYmax,0);  
    }
};

