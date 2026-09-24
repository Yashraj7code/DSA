class Solution {
public:
    int sum_of_digit(int n)
    {
        int sum=0;
        while(n>0)
        {
            int last=n%10;
            sum+=last;
            n=n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(i==sum_of_digit(nums[i]))
            {
                return i;
            }
        }
        return -1;
    }
};