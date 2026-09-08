class Solution {
public:
   long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0,high=0;
        long long sum=0,max_sum=0   ;
        unordered_map<int,int> freq;
        for(high=0;high<n;high++)
        {
            sum+=nums[high];
            freq[nums[high]]++;

            //keeping window k size
            if(high-low+1>k)
            {
                sum=sum-nums[low];
                freq[nums[low]]--;
                if(freq[nums[low]]==0)
                {
                    freq.erase(nums[low]);
                }
               
                low++;
            }
            //if window is size of k and all ements are distinct
            if(high-low+1==k && freq.size()==k)
            {
                max_sum=max(max_sum,sum);
            }

        }
        return max_sum;
    }
};