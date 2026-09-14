class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //create a array of 2 elements only 1 and 0 
        // increase every elment with sliding window if 0 gets higher than k shirnk window
        int low=0,high=0;
        int res=INT_MIN;
        vector<int> freq(2,0);  //to count 0 and 1 
        for(high=0;high<nums.size();high++)
        {
            freq[nums[high]]++;
            while(freq[0]>k)
            {
                
                freq[nums[low]]--;
                low++;
            }
            int len=high-low+1;
            res=max(res,len);
            
        }
        return res;

    }
};