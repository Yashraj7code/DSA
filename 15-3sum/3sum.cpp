class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;     //to avoid taking duplicate value
            }
            int left =i+1;
            int right =n-1;
            int sum= -1*nums[i];
            while(left<right)
            {
                int s= nums[left] + nums[right];
                if(s==sum)
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1])
                    {
                        left++;         //to get uniue value at left pointer
                    }
                    while(left <right && nums[right]==nums[right+1])
                    {
                        right--;         //to get uniue value at right pointer
                    }
                }
                else if(s<sum)
                {
                    left++;
                }
                else
                {
                    right--;
                }

            }
        }
        return res;
    }
};