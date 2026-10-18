class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    //    next_permutation(nums.begin(),nums.end());
    int n=nums.size();
    int breakpoint=-1;
    int i=0,j=0;
    int closest=0;
    for(i=n-2;i>=0;i--) 
    {
        if(nums[i]<nums[i+1])
        {
            breakpoint=i;
            break;
        }
    }
    if(breakpoint==-1)
    {
        reverse(nums.begin(),nums.end());
        return ;
    }
    for(j=n-1;j>breakpoint;j--)
    {
        if(nums[j]>nums[breakpoint])
        {
            swap(nums[j],nums[breakpoint]);
            break;
        }
    }
    reverse(nums.begin()+breakpoint+1,nums.end());
    }
};