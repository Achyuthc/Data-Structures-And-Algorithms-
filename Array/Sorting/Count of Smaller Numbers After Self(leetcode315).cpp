/*You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i]*/

tnums and tindex is for temporory nums array and temporory index array
ans stores the answer for each index
we store index to know where do we need to increment for answer
we know that ans increment when nums[i]<=nums[j] is number of elements in (nums[mid..... j-1] so mid-j)
class Solution {
public:
    int tnums[100001],tindex[100001];
    void merge(int left,int mid,int right,vector<int> &nums,vector<int>&index,vector<int>&ans)
    {
        int i=left,j=mid;
        int cnt=i;
        while((i<mid)&&(j<=right))
        {
            if(nums[i]<=nums[j])
            {
                tnums[cnt]=nums[i];
                tindex[cnt]=index[i];
                ans[index[i]]+=j-mid;
                i++;
            }
            else
            {
                tnums[cnt]=nums[j];
                tindex[cnt]=index[j];
                j++;
            }
            cnt++;
        }
        
        while(i<mid)
        {
            tnums[cnt]=nums[i];
            tindex[cnt]=index[i];
            ans[index[i]]+=j-mid;
            i++;
            cnt++;
        }
        while(j<=right)
        {
            tnums[cnt]=nums[j];
            tindex[cnt]=index[j];
            j++;
            cnt++;
        }
        for(i=left;i<=right;i++)
        {
            nums[i]=tnums[i];
            index[i]=tindex[i];
        }
        return ;
    }
    void mergesort(int left,int right,vector<int>&nums,vector<int> &index,vector<int> &ans)
    {
        if(left==right)
            return ;
        int mid=(left+right)/2;
        mergesort(left,mid,nums,index,ans);
        mergesort(mid+1,right,nums,index,ans);
        merge(left,mid+1,right,nums,index,ans);
        return ;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>index(nums.size());
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(0);
            index[i]=i;
        }
        
        mergesort(0,nums.size()-1,nums,index,ans);
        
        return ans;
        
    }
};
