/*Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 */

class NumArray {
public:
    vector<int> segment,v;
    int n;
    NumArray(vector<int>& nums) {
        v=nums;
        int twoPower=power(nums.size());
        segment.resize(4*nums.size(),0);
        n=nums.size()-1;
        
        constructTree(0,nums.size()-1,0,nums);
        //cout<<"jjaj";
    }
    void constructTree(int low,int high,int pos,vector<int> &nums)
    {
        if(low==high)
        {
            segment[pos]=nums[low];
            return ;
        }
        int mid=(low+high)/2;
        constructTree(low,mid,2*pos+1,nums);
        constructTree(mid+1,high,2*pos+2,nums);
        segment[pos]=segment[2*pos+1]+segment[2*pos+2];
        
        
    }
    void updateQuery(int low,int high,int &index,int &diff,int pos)
    {
        if(low>index||high<index)
            return ;
        segment[pos]+=diff;
        if(low==high)
        {
            return ;
        }
        int mid=(low+high)/2;
        
            updateQuery(low,mid,index,diff,2*pos+1);
            updateQuery(mid+1,high,index,diff,2*pos+2);
        
        
    }
    
    int RangeQuery(int low,int high,int &left,int &right,int pos)
    {
        if(high<left||low>right)
            return 0;
        if(low>=left&&right>=high)
        {
            return segment[pos];
        }
        int mid=(low+high)/2;
        return RangeQuery(low,mid,left,right,2*pos+1)+RangeQuery(mid+1,high,left,right,2*pos+2);
        
    }
    int power(int num)
    {
        int i=0;
        while((1<<i)<num)
        {
            i++;
        }
        return i;
    }
    void update(int index, int val) {
        
        int diff=val-v[index];
        v[index]=val;
        updateQuery(0,n,index,diff,0);
    }
    
    int sumRange(int left, int right) {
        return RangeQuery(0,n,left,right,0);
        
    }
};
