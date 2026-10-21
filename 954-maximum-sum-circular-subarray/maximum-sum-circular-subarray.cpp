class Solution {
public:
    int kadane_max(vector <int>&nums)
    {
    int i=0;
    int best_ending=nums[i];
    int ans=nums[i];
    for(i=1;i<nums.size();i++)
    {
        int choice_1=best_ending+nums[i];
        int choice_2=nums[i];
        best_ending=max(choice_1,choice_2);
        ans=max(ans,best_ending);

    }
    return ans;
    }
    int kadane_min(vector<int>&nums)
    {
    int i=0;
    int best_ending=nums[i];
    int ans=nums[i];
    for(i=1;i<nums.size();i++)
    {
        int choice_1=best_ending+nums[i];
        int choice_2=nums[i];
        best_ending=min(choice_1,choice_2);
        ans=min(ans,best_ending);

    }
    return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int min_sum=kadane_min(nums);
        int max_sum=kadane_max(nums);
        int sum=0;
        for(int x:nums)
        {
            sum+=x;
        }
        if(max_sum<0)
        {
            return max_sum;
        }

        return max(sum-min_sum,max_sum);
    }
};