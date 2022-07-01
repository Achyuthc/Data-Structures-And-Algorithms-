
/*You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

 */

class Solution {
public:
    static bool comp(vector<int> &v1,vector<int> &v2)
    {
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int numberOfBoxes=0;
        
        int i=0,boxes,ans=0;
        sort(boxTypes.begin(),boxTypes.end(),comp);
    
        while(i<boxTypes.size()&&truckSize>numberOfBoxes)
        {
             
            boxes=min(truckSize-numberOfBoxes,boxTypes[i][0]);
            numberOfBoxes+=boxes;
            ans+=boxes*boxTypes[i][1];
            i++;
            
        }
             
        return ans;
  }
};
