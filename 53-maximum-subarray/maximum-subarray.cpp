class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    //    int currsum=0,maxsum=INT_MIN;
    //    for(int i=0;i<nums.size();i++)
    //    {
    //     currsum+=nums[i];
    //     maxsum=max(maxsum,currsum);
    //     if(currsum<0)
    //     {
    //         currsum=0;
    //     }
        
    //    } 
    //    return maxsum;
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
};